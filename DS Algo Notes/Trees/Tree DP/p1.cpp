// http://codeforces.com/blog/entry/20935

/*
Given a tree T of N nodes, where each node i has Ci coins
attached with it. You have to choose a subset of nodes
such that no two adjacent nodes(i.e. nodes connected directly by an edge)
are chosen and sum of coins attached with nodes in chosen subset
is maximum.

*/


// dp2 : not included
// dp1 : included

#include<bits/stdc++.h>

using namespace std;

#define N 100000

vector<vector<int> > tree(N);
int C[N];

void dfs(int node, int parent){
    int s1=0, s2=0;
    for(int i=0; i<tree[node].size(); i++){
        if(tree[node][i] == parent)
            continue;
        dfs(tree[node][i], node);
        s1 += dp2[tree[node][i]];   // children is not included
        s2 += max(dp1[tree[node][i]], dp2[tree[node][i]]);  //dp1 : children not included!
    }
    dp1[node] = s1 + C[node];    // because s1 does not consider children as included
    dp2[node] = s2;
}

int main(){
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    int ans = max(dp1[1], dp2[1]);
    cout << ans << endl;
}


