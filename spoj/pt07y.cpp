#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > tree(10005);
int vis[10005] = {0};

void dfs(int node){
    if(vis[node])
        return;
    vis[node] = 1;
    for(int i=0; i<tree[node].size(); i++){
        dfs(tree[node][i]);
    }
}

int main(){
    int n, m, u, v;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        scanf("%d%d",&u,&v);
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }
    if(m != n-1)
        printf("NO\n");
    else{
        dfs(0);
        int ans = 1;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                ans = 0;
                break;
            }
        }
        if(!ans)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
