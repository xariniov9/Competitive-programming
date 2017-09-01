
// HIMANSHU TIWARI
// XARINIOV9


// JAN'17 LONG CHALLENGE



#include<bits/stdc++.h>

using namespace std;

// GHADI DETERGENT..

// PEHLE ISTEMAAL KAREIN FIR VISHWAAS KAREIN..

// HAPPY NEW YEAR..


vector<pair<int, int> > E;
set< pair<int, int> > R;
int vis[100005] = {0};
vector<list<int> > adjList(100005);
vector<int> tour;
struct ed{int s, d, rev; };
vector<vector<ed> > adj;
int n=0;

long long MOD;
long long MAXX = 1000000009;


void addEdge(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    n = max(n, max(u, v)+1);
    if(adj.size()<n) adj.resize(n);
    adj[u].push_back({u, v, (int)adj[v].size()});
    adj[v].push_back({v, u, (int)adj[u].size()-1});
}

void dfs(int v){
    vis[v] = 1;
    for(list<int>:: iterator it = adjList[v].begin(); it!=adjList[v].end(); it++)
        if(!vis[*it])
            dfs(*it);
}

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



long long modularMult(long long a, long long b){
    if(MOD <= MAXX)
        return a * b% MOD;
    long long res = 0;
    while(a>0){
        if(a & 1) {
            res += b;
            if(res >= MOD)
                res = res - MOD;
        }
        a >>= 1;
        b <<= 1;
        if(b >= MOD)
            b = b-MOD;
    }
    return res;
}

bool isEuler(int n){
// AN UNDIRECTED GRAPH HAS EULER CYCLE IFF

    //1. ALL NODES HAVE EVEN DEGREE
    //2. ONLY ONE CONNECTED COMPONENT
    int i, o=0; bool connected=true;
    for(i=0; i<n; i++)
        if(adj[i].size() != 0)
            break;
    if(i!=n){
        dfs(i);
        for(int i=0; i<n; i++)
            if(vis[i] == 0 && adjList[i].size()>0)
                connected=false;
    }
    if(!connected)  return 0;
    for(int i=0; i<n; i++){
        if(adjList[i].size() & 1)
            return false;
    }
    return true;
}
// AS I ALWAYS ADD A TIME-PASS FUNCTION TO MY CODE.. HERE IT GOES..

void printAletter(char * nameOfGirl){

    printf("Hello!\n");
    printf("Dear %s,",nameOfGirl);
    printf("If there is anything more honorable than this I would bestow u with that too.. words wont be able to define the bond I share with u dear friend...u add life to my dull and boring days...much love dear friend..thankyou for being in my life..a true blessing u are!!!\n\n\nThank you for being there for me when I call you and need someone to just listen. It doesn’t matter where we are in this world or in our lives, I know you will always pick me.\n\n\n\nwords cant describe how much i value u, u ve been mre dan a best friend to me...you deserve more than a Gold medal...i heart u plenty plenty.");

    return;
}

void TimePass(int n){

    char nameOfGirl[25];
    while(1){
        scanf("%s",nameOfGirl);
        printAletter(nameOfGirl);
    }

    // DID YOU NOTICE I DIDN'T DO ANYTHING WITH n..
    return;
}


void path(int u){
   while(!adj[u].empty()){
        ed e = adj[u].back();
        adj[u].pop_back();
        if(e.s >= 0){
            adj[e.d][e.rev].s = -1;
            path(e.d);
        }
   }
   tour.push_back(u);
}

void eulerianCycle(){
    int m=0, x;
    int s=0;
    for(int u=0; u<n; ++u){
        x = adj[u].size();
        m += x;
        if(x>0) s=u;
    }
    tour.clear();
    path(s);
}
int main(){
    int n, e, u, v;
    scanf("%d%d",&n, &e);
    for(int i=0; i<e; i++){
        scanf("%d %d",&u,&v);
        E.push_back(make_pair(u, v));
        addEdge(u-1, v-1);
    }

    if(!isEuler(n)){
        printf("NO\n");
    } else {
        printf("YES\n");
        eulerianCycle();
        for(int i=0; i<tour.size()-1; i++){
            R.insert(make_pair(tour[i]+1, tour[i+1]+1));
        }
        R.insert(make_pair(tour[tour.size()-1]+1, tour[0]+1));
        for(int i=0; i<E.size(); i++){
            if(R.find(E[i]) != R.end())
                printf("%d %d\n",E[i].first, E[i].second);
            else
                printf("%d %d\n",E[i].second, E[i].first);
        }
    }
    return 0;
}

// MUJH PAR EK EHSAAN KARNA KI MUJHPAR KOI EHSAAN NA KARNA

/*


	hud hud dabang dabang dabang..


*/



/*

// HIMANSHU TIWARI
// XARINIOV9


// JAN'17 LONG CHALLENGE

#include<stdio.h>


// GHADI DETERGENT..

// PEHLE ISTEMAAL KAREIN FIR VISHWAAS KAREIN..

// HAPPY NEW YEAR..

void solve(int C, int D, int L){
    L -= D*4;
    if(L%4 || L<0){
        printf("no\n");
        return;
    } else {
        L/=4;
        if(L<=C && C-L <= 2*D){
            printf("yes\n");
            return;
        }
        printf("no\n");
    }
    return;
}

// AS I ALWAYS ADD A TIME-PASS FUNCTION TO MY CODE.. HERE IT GOES..

void printAletter(char * nameOfGirl){

    printf("Hello!\n");
    printf("Dear %s,",nameOfGirl);
    printf("If there is anything more honorable than this I would bestow u with that too.. words wont be able to define the bond I share with u dear friend...u add life to my dull and boring days...much love dear friend..thankyou for being in my life..a true blessing u are!!!\n\n\nThank you for being there for me when I call you and need someone to just listen. It doesn’t matter where we are in this world or in our lives, I know you will always pick me.\n\n\n\nwords cant describe how much i value u, u ve been mre dan a best friend to me...you deserve more than a Gold medal...i heart u plenty plenty.");

    return;
}

void TimePass(int n){

    char nameOfGirl[25];
    while(1){
        scanf("%s",nameOfGirl);
        printAletter(nameOfGirl);
    }

    // DID YOU NOTICE I DIDN'T DO ANYTHING WITH n..
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long Cats, Dogs, Legs;
        scanf("%lld%lld%lld",&Cats,&Dogs,&Legs);
        solve(Cats, Dogs, Legs);
    }
    return 0;
}


*/

