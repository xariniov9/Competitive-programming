#include<bits/stdc++.h>

#define N 100001

using namespace std;

vector<vector<int> > adj(N);
bool vis[N];
int disc[N];            // shows dicovered time
int Time = 0;
int parent[N];
int low[N];


void dfs(int node, int parent){
    vis[node] = 1;
    Time++;
    disc[node] = Time;
    int child = 0;
    for(int i=0; i<tree[node].size(); i++){
        if(vis[tree[node][i] == false){
            parent[tree[node][i]] = node;
            child++;
            dfs(tree[node][i]);
            low[node] = min(low[tree[node][i]], low[node]);
            if(low[tree[node][i]] > disc[node])
                printf("(%d %d)\n",node, tree[node][i]);
        } else if(parent[node] != adj[node][i]){
            low[node] = min(disc[adj[node][i], low[node]);
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
    return 0;
}

