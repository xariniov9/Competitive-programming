#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int> > > tree(50005);
int vis[50005];

bool cmp(const int &a, const int &b){
    return a>b;
}
pair<int, int> solve(int idx){
    if(vis[idx]){
        pair<int, int> ret = make_pair(-1, -1);
        return ret;
    }

    if(tree[idx].size() == 0){
        pair<int, int> ret = make_pair(0, 0);
        return ret;
    }

    vis[idx]  = 1;

    pair<int, int> ans = make_pair(0, 0);
    vector<int> hts;
    for(int i=0; i<tree[idx].size(); i++){
        pair<int, int> small = solve(tree[idx][i].first);
        if(small.first == -1)
            continue;
        //printf("state: %d %d %d\n",idx, small.first, small.second);
        hts.push_back(tree[idx][i].second + small.first);

        ans.first = max(tree[idx][i].second + small.first, ans.first);
        ans.second = max(small.second, ans.second);
    }
    sort(hts.begin(), hts.end(), cmp);
    int dia = 0;
    for(int i=0; i<min(2,(int)hts.size()); i++)
        dia += hts[i];
    ans.second = max(ans.second, dia);

    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, u, v, w;
        scanf("%d",&n);
        for(int i=0; i<n-1; i++){
            scanf("%d %d %d",&u,&v,&w);
            tree[u-1].push_back(make_pair(v-1, w));
            tree[v-1].push_back(make_pair(u-1, w));
        }
        for(int i=0; i<=n; i++)
            vis[i] = 0;
        pair<int, int> ans= solve(0);

        printf("%d\n",ans.second);

        for(int i=0; i<=n; i++)
            tree[i].clear();
    }

    return 0;
}
