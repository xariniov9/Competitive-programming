
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int> > > graph(1005);
set< pair<pair<int, int>, int> > edges;

int visM[1005] = {0};
int visW[1005] = {0};

void solve(int idx, int pth){
    if(visM[idx] && visW[idx])
        return;
    if((pth ==1 && visW[idx] == 0) || (pth==2 && visM[idx] == 0))
        return;
    if(pth == 1 || pth == 3)
    visM[idx] = 1;
    if(pth == 3)
        visW[idx] = 1;
    for(int i=graph[idx].size() - 1; i>=0; i--){
        if(pth == 3){
            solve(graph[idx][i].first, pth);
            edges.insert(make_pair(make_pair(idx, graph[idx][i].first), graph[idx][i].second));
        }else if(graph[idx][i].second == pth){
            solve(graph[idx][i].first, pth);
            edges.insert(make_pair(make_pair(idx, graph[idx][i].first), graph[idx][i].second));
        }
    }
}
int main(){

    int n, m, u, v, w;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        scanf("%d%d%d",&u,&v,&w);
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
}
