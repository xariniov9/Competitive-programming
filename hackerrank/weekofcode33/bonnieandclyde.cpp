#include<bits/stdc++.h>
#define N 100002

using namespace std;

int u, v, w;
vector<vector<int> > adj(100005);
vector<vector<int> > adj1(100005);

int p[100005];
bool vis[100005];
int disc[N];            // shows dicovered time
int Time = 0;
int parent[N];
int low[N];
bool AP[N];

void init(int n){
    for(int i=0; i<=n; i++)
        p[i] = i;
    Time=0;
    for(int i=0; i<N; i++){
        parent[i] = -1;
        low[i] = 100*N;
        vis[i] = false;
        AP[i] = false;
    }
}

int Find(int x){
    if(p[x] == x)
        return x;
    return p[x] = Find(p[x]);
}

void Merge(int u, int v){
    int pu = Find(u);
    int pv = Find(v);

    p[pu] = pv;
}

void DFS(int node){
    vis[node] = true;
    disc[node] = Time+1;
    Time++;
    int child =0;
    for(int i=0; i<adj[node].size(); i++){
        if(vis[adj[node][i]] == false){
            child++;
            parent[adj[node][i]] = node;
            DFS(adj[node][i]);
            low[node] = min(low[node], low[adj[node][i]]);
            if(parent[node] == -1 && child > 1)
                AP[node] = true;
            if(parent[node] != -1 && low[adj[node][i]] >= disc[node])
                AP[node] = true;
        }else if(parent[node] != adj[node][i]){
            low[node] = min(low[node], disc[adj[node][i]]);
        }
    }
}

/*int Find(int cur, int node){
    if(cur == node){
        return 0;
    }
    int ans = -1;
    for(int i=0; i<adj1[cur].size(); i++){
        if(adj1[cur][i] != parent[cur]){
            ans = Find(adj1[cur][i]);
            if(ans != -1)
                return i;
        }
    }
    return -1;
}*/

int Find(int cur, int node){
    if(low[node] < disc[cur])
        return 0;
    if(low[node] == disc[cur])
        return 1;
}

int main(){
    int u, v, n, m, q;
    scanf("%d%d%d",&n,&m,&q);
    init(n);
    memset(parent, -1, sizeof parent);
    for(int i=0; i<m; i++){
        scanf("%d%d",&u,&v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
        Merge(u-1, v-1);
    }
    for(int i=0; i<n; i++)
        if(vis[i] == false)
            DFS(i);

    int ap=0;
    vector<int> APs;
    for(int i=0; i<=n; i++){
        if(AP[i]){
            APs.push_back(i);
            ap++;
        }
    }
    printf("parent : ");
    for(int i=0; i<n; i++)
        printf("%d ",parent[i]);
    printf("\nAP's : ");
    for(int i=0; i<n; i++)
        if(AP[i])
            printf("%d ",i);
    printf("\n");

    for(int i=0; i<n; i++){
        if(parent[i] != -1){
            adj1[i].push_back(parent[i]);
            adj1[parent[i]].push_back(i);
        }
    }
    printf("adj1 : \n");
    for(int i=0; i<n; i++){
        printf("i = %d : ",i);

        for(int j=0; j<adj1[i].size(); j++)
            printf("%d ",adj1[i][j]);
        printf("\n");
    }
    while(q--){
        //int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        u--; v--; w--;
        if(Find(u) != Find(v) || Find(v) != Find(w) || Find(u) != Find(w)){
            printf("NO\n");
            continue;
        }
        if(ap==0)
            printf("YES\n");
        else if(AP[w]){

            int ui = Find(w, u);
            int vi = Find(w, v);
            printf("ui, vi : %d %d\n",ui, vi);
            if(ui == vi)
                printf("NO\n");
            else
                printf("YES\n");
        }
        else{
            int ui, vi, wi;
            int flag = 0;
            for(int i=0; i<APs.size(); i++){
                ui = Find(APs[i], u);
                vi = Find(APs[i], v);
                wi = Find(APs[i], w);
                if(ui != vi || vi != wi || ui != wi){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                printf("NO\n");
            } else
                printf("YES\n");
        }
    }
    return 0;
}
