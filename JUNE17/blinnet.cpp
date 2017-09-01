#include<bits/stdc++.h>

using namespace std;

char city[20000];

int p[20000];

vector<pair< pair<int, int>, int> > edges;

bool cmp(const pair<pair<int, int>, int>&a, const pair<pair<int, int>, int>&b){
    return a.second < b.second;
}

int find(int x){
    if(p[x] == x)
        return x;
    p[x] = find(p[x]);
    return p[x];
}

void link(int u, int v){
    int pu = find(u);
    int pv = find(v);
    p[pu] = pv;
}

int kruskal(){
    int ans = 0;
    sort(edges.begin(), edges.end(), cmp);
    for(int i=0; i<edges.size(); i++){
        if(find(edges[i].first.first)!=find( edges[i].first.second)){
            ans += edges[i].second;
            link(edges[i].first.first, edges[i].first.second);
        }
    }
    return ans;
}

void init(int n){
    edges.clear();
    for(int i=0; i<=n; i++)
        p[i] = i;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, e, neigh, cost;
        scanf("%d",&n);
        init(n); //dsu, edges
        for(int i=0; i<n; i++){
            scanf("%s",city);
            scanf("%d",&e);
            for(int j=0; j<e; j++){
                scanf("%d%d",&neigh, &cost);
                edges.push_back(make_pair(make_pair(i, neigh-1), cost));
            }
        }
        printf("%d\n",kruskal());

    }
    return 0;
}
