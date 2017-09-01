
// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-destructive-mind/

#include<bits/stdc++.h>
using namespace std;

#define N 201

vector<vector<int> > adj(N);
bool vis[N];
int low[N];
int parent[N];
bool AP[N];
int disc[N];
int Time;

void init(){
    Time = 0;
    for(int i=0; i<N; i++){
        vis[i] = false;
        low[i] = 1000000;
        parent[i] = -1;
        AP[i] = false;
        disc[i] = 0;
    }
}

void DFS(int node){

    vis[node] = true;
    Time++;
    disc[node] = Time;
    int child = 0;
    for(int i=0; i<adj[node].size(); i++){
        if(vis[adj[node][i]] == false){
            child++;
            parent[adj[node][i]] = node;
            DFS(adj[node][i]);
            low[node] = min(low[node], low[adj[node][i]]);
            if(parent[node] == -1 && child > 1)
                AP[node] = true;
            if(parent[node] != -1 && low[adj[node][i]] >= disc[node] )
                AP[node] = true;
        } else if(parent[node] != adj[node][i]){
            low[node] = min(low[node], disc[adj[node][i]]);
        }
    }
}

int main(){
    init();
    int n, m, q, u, v;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        scanf("%d%d",&u,&v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    for(int i=0; i<n; i++)
        if(vis[i] == false)
            DFS(i);
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        if(AP[x-1])
            printf("Satisfied %d\n",adj[x-1].size());
        else
            printf("Not Satisfied\n");
    }
    return 0;
}
