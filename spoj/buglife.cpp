#include<bits/stdc++.h>

using namespace std;

int c[20005];
vector<vector<int> > graph(20005);

bool dfs(int idx){
    bool res = true;
    for(int i=0; i<graph[idx].size(); i++){
        if(c[graph[idx][i]] == c[idx])
            return false;

        if(c[graph[idx][i]] == 0){
            c[graph[idx][i]] = (c[idx]==1) ? 2 : 1;
            res = res && dfs(graph[idx][i]);
        }
    }
    return res;
}

int main(){
    int t;
    int tc = 1;
    scanf("%d",&t);
    while(t--){
        int n, m, u, v;
        memset(c, 0, sizeof c);
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++)
            graph[i].clear();
        for(int i=0; i<m; i++){
            scanf("%d%d",&u,&v);
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        bool ans = true;
        for(int i=0; i<=n; i++){
            if(!c[i]){
                c[i] = 1;
                ans = ans && dfs(i);
            }
        }
        printf("Scenario #%d:\n",tc);
        if(ans)printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
        tc++;
    }
}
