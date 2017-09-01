#include<bits/stdc++.h>

#define N 100001

using namespace std;

vector<vector<int> > adj(N);
bool vis[N];
int disc[N];            // shows dicovered time
int Time = 0;
int parent[N];
int low[N];
bool AP[N];

int DFS(int node){
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

void init(){
    Time=0;
    for(int i=0; i<N; i++){
        parent[i] = -1;
        low[i] = 2*N;
        vis[i] = false;
        AP[i] = false;
    }
}
int main(){
    init();
    int n, m, u, v;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        scanf("%d%d",&u,&v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    for(int i=0; i<n; i++)
        if(!vis[i])
            DFS(i);
    printf("AP: ");
    for(int i=0; i<n; i++)
        if(AP[i])
            printf("%d ",i);
    printf("\n");
}
