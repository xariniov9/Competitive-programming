        // HIMANSHU TIWARI
        // XARINIOV9


        // JAN'17 LONG CHALLENGE



        #include<bits/stdc++.h>

        // GHADI DETERGENT..

        // PEHLE ISTEMAAL KAREIN FIR VISHWAAS KAREIN..

        // HAPPY NEW YEAR..


        using namespace std;

        long long MOD;
        long long MAXX = 1000000009;


        typedef long long int LLI;

        //----------------UTILITY FUNCTIONS TO PERFORM MODULO ARITHMATIC ON NUMBERS----------//
        inline int
        addMod( int a, int b){
        	LLI v=a;
        	v+=b;
        	if(v>=MOD) v-=MOD;
        	return (int)v;
        }
        inline int
        subMod( int a, int b){
        	int v = a-b;
        	if(v<0)	v+=MOD;
        	return v;
        }

        int adhiktam( int a, int b){
        	if(a > b)
        		return a;
        	else
        		return b;
        }

        int nyoontam(int a, int b){
        	if(a < b)
        		return a;
        	else
        		return b;
        }
        //=====================================================================================//



        int a[35][35][35];

        set<int> leaves;
        int maxLeaf = 0;
        struct node {
            int value, blacks, whites, perfectChildren;
            bool isPerfect;
        } tree[4 * 35 * 35 * 35];


        void buildTree(int idx, int x, int y, int z, int Size){
            if(Size == 1){
                tree[idx].value = 1;
                tree[idx].isPerfect = true;
                if(a[x][y][z]){
                    tree[idx].whites = 1;
                    tree[idx].blacks = 0;
                }else {
                    tree[idx].whites = 0;
                    tree[idx].blacks = 1;
                }
                tree[idx].perfectChildren = 0;
                leaves.insert(idx);
                maxLeaf = max(maxLeaf, idx);
                return;
            }

            int itr=0;
            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    for(int k=0; k<2; k++){
                        buildTree(8 * idx + itr, x + i * Size/2,
                                                 y + j * Size/2,
                                                 z + k * Size/2,
                                                 Size/2);
                        itr++;
                    }
                }
            }
            tree[idx].perfectChildren = 0;
            tree[idx].value = 0;
            tree[idx].isPerfect = false;
           for(int i=0; i<8; i++){
                tree[idx].whites += tree[8 * idx + i].whites;
                tree[idx].blacks += tree[8 * idx + i].blacks;
                if(tree[8 * idx + i].isPerfect)
                    tree[idx].perfectChildren++;
                tree[idx].value += tree[8*idx+i].value;
           }
           if(tree[idx].blacks == 0 || tree[idx].whites == 0){
                tree[idx].value = 1;
                tree[idx].isPerfect = true;
                return;
           }
        }


        class cmp {
            public :
            bool operator()(const pair<int, pair<int, int> >&a, const pair<int, pair<int, int> >&b){
                if(a.first == b.first){
                    if(a.second.second == b.second.second)
                        return tree[a.second.first].perfectChildren < tree[a.second.first].perfectChildren;
                    return a.second.second > b.second.second;
                }
                return a.first > b.first;
            }
        };


        int findMinimal(int k){
            if(k==0)
                return tree[1].value;
            priority_queue< pair<int, pair<int, int> >, vector<pair< int, pair<int, int> > >, cmp> pq;
            pq.push(make_pair(1, make_pair(1, min(tree[1].blacks, tree[1].whites) )));
            int minimal = 0;

            while(!pq.empty()){
                pair<int, pair<int, int> > top = pq.top();
                pq.pop();
                if( (k >= min(tree[top.second.first].blacks, tree[top.second.first].whites) && leaves.find(top.second.first) != leaves.end()) ||
                    ((k >= min(tree[top.second.first].blacks, tree[top.second.first].whites) && min(tree[top.second.first].blacks, tree[top.second.first].whites)<15 && tree[top.second.first].perfectChildren >= 5) )){
                    k -= min(tree[top.second.first].blacks, tree[top.second.first].whites);
                    minimal += 1;
                } else {
                    for(int i =0; i<8 && 8*top.second.first + i <= maxLeaf ; i++){
                        pq.push(make_pair(top.first+1, make_pair(8*top.second.first + i, min(tree[8 * top.second.first + i].blacks, tree[8 * top.second.first + i].whites))));
                    }
                }
            }
            return minimal;
        }

        void make_changes(int idx){
            if(leaves.find(idx) != leaves.end())
                return;
            if(idx > maxLeaf)
                return;
            for(int i=0; i<8; i++)
                make_changes(8*idx + i);

            tree[idx].perfectChildren = 0;
            tree[idx].value = 0;
            tree[idx].isPerfect = false;
           for(int i=0; i<8; i++){
                tree[idx].whites += tree[8 * idx + i].whites;
                tree[idx].blacks += tree[8 * idx + i].blacks;
                if(tree[8 * idx + i].isPerfect)
                    tree[idx].perfectChildren++;
                tree[idx].value += tree[8*idx+i].value;
           }
           if(tree[idx].blacks == 0 || tree[idx].whites == 0){
                tree[idx].value = 1;
                tree[idx].isPerfect = true;
                return;
           }

        }
        void update(int idx){
            if(idx > maxLeaf)
                return;
            if(leaves.find(idx) != leaves.end()){
                if(tree[idx].blacks){
                    tree[idx].whites = 1;
                    tree[idx].blacks = 0;
                } else {
                    tree[idx].whites = 0;
                    tree[idx].blacks = 1;
                }
                return;
            }

            update(8 * idx + 1);

            tree[idx].perfectChildren = 0;
            tree[idx].value = 0;
            tree[idx].isPerfect = false;
           for(int i=0; i<8; i++){
                tree[idx].whites += tree[8 * idx + i].whites;
                tree[idx].blacks += tree[8 * idx + i].blacks;
                if(tree[8 * idx + i].isPerfect)
                    tree[idx].perfectChildren++;
                tree[idx].value += tree[8*idx+i].value;
           }
           if(tree[idx].blacks == 0 || tree[idx].whites == 0){
                tree[idx].value = 1;
                tree[idx].isPerfect = true;
                return;
           }
        }

        int Maximal(int k){
            queue<pair<int, int> > pq;
            if(k>0)
                pq.push(make_pair(1, 1));
            int currLevel = 1;
            while(!pq.empty()){
                pair<int, int> top = pq.front();
                pq.pop();

                if(top.first > currLevel){
                    make_changes(1);
                    currLevel++;
                }
                if(k>=1){
                    if(tree[top.second].isPerfect && (leaves.find(top.second) == leaves.end())){
                        update(top.second);
                        k--;
                    }
                }
                for(int i=0; i<8 && (8 * top.second + i)<=maxLeaf; i++)
                    pq.push(make_pair(top.first + 1, 8 * top.second + i));
            }
            make_changes(1);
            return tree[1].value;
        }




        int main(){
            int n, k;
            scanf("%d%d",&n,&k);

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    for(int k=0; k<n; k++){
                        scanf("%d",&a[i][j][k]);
                    }
                }
            }
            if(n==1){
                printf("1 1\n");
            }
            buildTree(1, 0, 0, 0, n);

            if(n>1){
                int minimal = findMinimal(k);
                int maximal = Maximal(k);
                printf("%d %d\n",minimal, maximal);
                //assert(maximal == (n*n*n));
            }
            return 0;
        }



        // MUJH PAR EK EHSAAN KARNA KI MUJHPAR KOI EHSAAN NA KARNA

        /*

        	hud hud dabang dabang dabang..
        */


        /*
        8 1
        1 1 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
        1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
        1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
        1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
        1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
        1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
        1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
        1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
        */
    // && tree[top.second.first].perfectChildren < 7
