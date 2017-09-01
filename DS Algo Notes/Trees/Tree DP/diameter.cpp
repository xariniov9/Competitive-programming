#include<bits/stdc++.h>

using namespace std;

// dp1 : represents height
// dp2 : represents diameter

int dia=0;
void dfs(int node, int parent){
    int s1=0, s2=0;
    vector<int> subtree;

    for(int i=0; i<tree[node].size(); i++){
        if(tree[node][i] == parent)
            continue;
        dfs(tree[node][i], node);
        subtree.push_back(dp1[tree[node][i]]);
    }
    sort(subtree.begin(), subtree.end());


    else if(subtree.size() >= 1)
        dp1[node] = 1 + subtree[subtree.size() - 1];
    if(subtree.size() >= 2){
        dp2[node] = 2 + subtree.back() + subtree[subtree.size()-2];
    }
    dp2[node] = max(dp1[node], s2);
    dia = max(dia, max(dp1[node], dp2[node]));
}

int main(){


}
