#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > tree(100000);
char s[100005];
char p[105], revp[105];
char newS[100005];
char newS1[100005];

int maxHeight = 0, plen;
int P[100005];
int T[100005];
int L[100005];
int subsize[100005];

int pa[20][100005];

int chainNo=0, chainHead[100005], chainPos[100005], chainInd[100005], chainSize[100005] = {0};

vector<vector<int> > chains;

void HLD(int cur, int parent){

    if(chainHead[chainNo] == -1){
        chainHead[chainNo] = cur;       //start new chain
        vector<int> newchain;
        //newchain.push_back(cur);
        chains.push_back(newchain);
    }
    chainInd[cur] = chainNo;            //index of chain to which node belongs
    chainPos[cur] = chainSize[chainNo]; //Given a node, what is its position in its chain
    chainSize[chainNo]++;
    chains[chainNo].push_back(cur);

    int ind = -1, mai=-1;
    for(int i=0; i<tree[cur].size(); i++){
        if(subsize[tree[cur][i]] > mai && tree[cur][i] != parent){
            mai = subsize[tree[cur][i]];
            ind = i;
        }
    }
    if(ind >= 0)                        //note not called on leaves
        HLD(tree[cur][ind], cur);             //special child

    for(int i=0; i<tree[cur].size(); i++){
        if(i != ind && tree[cur][i] != parent){
            chainNo++;
            HLD(tree[cur][i], cur);
        }
    }
}

void initDFS(int node, int parent, int level){
    L[node] = level;
    T[node] = parent;
    subsize[node] = 1;
    pa[0][node] = parent;
    maxHeight = max(maxHeight, level);
    for(int i=0; i<tree[node].size(); i++){
        if(tree[node][i] != parent){
            initDFS(tree[node][i], node, level+1);
            subsize[node] += subsize[tree[node][i]];
        }
    }
}

int LCA1(int u, int v) {
	if(L[u] < L[v]) swap(u,v);
	int diff = L[u] - L[v];
	for(int i=0; i<=18; i++)
        if( (diff>>i)&1 )
            u = pa[i][u];
	if(u == v)
        return u;
	for(int i=18; i>=0; i--)
        if(pa[i][u] != pa[i][v]) {
            u = pa[i][u];
            v = pa[i][v];
        }
	return pa[0][u];
}

void computeLPSArray(char *pat, int M, int *lps){
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;
    while (i < M){
        if (pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if (len != 0){
                len = lps[len-1];

            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(char *pat, char *txt){
    int ret=0;
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N){
        if (pat[j] == txt[i]){
            j++;
            i++;
        }
        if (j == M){
            ret++;
            j = lps[j-1];
        }
        else if (i < N && pat[j] != txt[i]){
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return ret;
}

vector<int> KMPSearch1(char *pat, char *txt){
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    vector<int> ret;
    computeLPSArray(pat, M, lps);
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N){
        if (pat[j] == txt[i]){
            j++;
            i++;
        }
        if (j == M){
            ret.push_back(i-j);
            j = lps[j-1];
        }
        else if (i < N && pat[j] != txt[i]){
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return ret;
}
vector<vector<int> > DU;
vector<vector<int> > UD;
char tmp[300];
char tmp1[300];


// UD COMPARED WITH REVERSE
// DU COMPARED WITH NORMAL
int binarySearchForLeftRange(vector<int> &a, int length, int left_range){
    if(length == 0)
        return -1;
    if (a[length-1] < left_range)
        return -1;

    int low = 0;
    int high = length-1;

    while (low<=high){
        int mid = low+((high-low)/2);

        if(a[mid] >= left_range)
            high = mid-1;
        else //if(a[mid]<i)
            low = mid+1;
    }
    return high+1;
}

int binarySearchForRightRange(vector<int> &a, int length, int right_range){
    if(length == 0)
        return -1;
    if (a[0] > right_range)
        return -1;

    int low = 0;
    int high = length-1;

    while (low<=high){
        int mid = low+((high-low)/2);

        if(a[mid] > right_range)
            high = mid-1;
        else //if(a[mid]<i)
            low = mid+1;
    }
    return low-1;
}

int inRange(vector<int> &a, int left_range, int right_range){
    int length = a.size();
    int index_left = binarySearchForLeftRange(a, length, left_range);
    int index_right = binarySearchForRightRange(a, length, right_range);
    int count = 0;
    if (index_left==-1 || index_right==-1 || index_left>index_right)
        count = 0;
    else
        count = index_right-index_left+1;
    return count;
}
int bruteForce(int u, int v){
    int lca= LCA1(u, v);
    int ans = 0;
//    printf("u,v : %d %d\n",u, v);
    if(chainInd[u] == chainInd[v]){
        int uchain = chainInd[u];
        if(chainPos[u] >= chainPos[v] ){
            //use UD
            ans = inRange(UD[uchain], chainPos[v], chainPos[u] - plen + 1);
            /*if(lb != UD[uchain].begin()){
                if(*lb > chainPos[u] - plen + 1)
                    lb = lb-1;
            }
            if(lb != UD[uchain].begin()){
                if(*lb > chainPos[v])
                    lb = lb-1;
            }
            for(int i=0; i<UD[uchain].size(); i++){
                if(UD[uchain][i] >= chainPos[v] && UD[uchain][i] + plen - 1 <= chainPos[u])
                    ans++;
            }*/
        } else{
            ans = inRange(DU[uchain], chainPos[u], chainPos[v] - plen + 1);
            /*for(int i=0; i<DU[uchain].size(); i++){
                if(DU[uchain][i] >= chainPos[u] && DU[uchain][i] + plen -1 <= chainPos[v])
                    ans++;
            }*/
        }
        return ans;
    }

    if(chainInd[lca] == chainInd[u] && lca != u){
        ans = bruteForce(u, lca) + bruteForce(lca, v);
        return ans;
    }
    if(chainInd[lca] == chainInd[v] && lca != v){
        ans = bruteForce(u, lca) + bruteForce(lca, v);
        return ans;
    }

    int itr=0;
    while(u != lca){
        newS[itr++] = s[u];
        u = T[u];
    }
    newS[itr++] = s[lca];
    int itr1 = 0;
    while(v != lca){
        newS1[itr1++] = s[v];
        v = T[v];
    }
    for(int i=itr1-1; i>=0; i--){
        newS[itr++] = newS1[i];
    }
    newS[itr] = '\0';
    //printf("newS : %s\n",newS);*/
    return KMPSearch(p, newS);
}

int viss[100005] = {0};

int main(){
    int n, q, u, v;
    memset(chainHead, -1, sizeof chainHead);
    memset(pa, -1, sizeof pa);
    scanf("%d%d",&n,&q);
    scanf("%s\n%s",s, p);
    for(int i=0; i<n-1; i++){
        scanf("%d%d",&u,&v);
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }
    initDFS(0, -1, 0);

    for(int i=1; i<=18; i++)
        for(int j=0; j<n; j++)
            if(pa[i-1][j] != -1)
                pa[i][j] = pa[i-1][pa[i-1][j]];
    plen = strlen(p);
    HLD(0, -1);
    for(int i=0; i<plen; i++)
        revp[plen-i-1] = p[i];
    revp[plen] = '\0';
    vector<pair<int, int> > queries;
    /*for(int i=0; i<=chainNo; i++){
        for(int j=0; j< chains[i].size(); j++)
            newS[j] = s[chains[i][j]];
        newS[chains[i].size()] = '\0';
        vector<int> downtoUp = KMPSearch1(p, newS);
        DU.push_back(downtoUp);
        vector<int> uptodown = KMPSearch1(revp, newS);
        UD.push_back(uptodown);
    }*/
//    memset(viss, 1, sizeof viss);
    while(q--){
        scanf("%d%d",&u,&v);
        u--; v--;
        queries.push_back(make_pair(u, v));
        viss[chainInd[u]] = 1;
        viss[chainInd[v]] = 1;

//        printf("%d\n",bruteForce(u, v));
    }
    for(int i=0; i<=chainNo; i++){
        vector<int> downtoUp, uptodown;
        if(!viss[i]){
            DU.push_back(downtoUp);
            UD.push_back(uptodown);
            continue;
        }
        for(int j=0; j< chains[i].size(); j++)
            newS[j] = s[chains[i][j]];
        newS[chains[i].size()] = '\0';
        downtoUp = KMPSearch1(p, newS);
        DU.push_back(downtoUp);
        uptodown = KMPSearch1(revp, newS);
        UD.push_back(uptodown);
    }
    for(int i=0; i<queries.size(); i++){
        printf("%d\n",bruteForce(queries[i].first, queries[i].second));
    }
    return 0;
}
