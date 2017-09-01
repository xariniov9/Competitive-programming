#include<bits/stdc++.h>
#define N 100000
using namespace std;

vector<vector<int> > graph;
int Time=0;
int L[N];                   // level
int disc[N];                // discovery time
bool vis[N];                // visited
int low[N];                 // lowest discovery time (back edge)
int P[N];                   // parent in dfs


//Assuming the graph is connected initially
bool isBiconnected(int node, int parent){
    Time++;
    disc[node] = Time;
    vis[node] = true;
    int child = 0;
    for(int i=0; i<graph[node].size(); i++){
        if(!vis[graph[node][i]]){
            child++;
            P[graph[node][i]] = node;
            bool result = isBiconnected(graph[node][i], node);
            if(!result)
                return false;
            low[node] = min(low[node], low[graph[node][i]]);
            if(P[node]!=-1 && child > 1)
                return false;
            if(P[node]!=-1 && low[graph[node][i]] >= disc[node])
                return false;
        } else if(P[node] != graph[node][i]){
            low[node] = min(low[node], disc[graph[node][i]]);
        }
    }
    return true;
}

int main(){


}
