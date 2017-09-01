#include<bits/stdc++.h>

using namespace std;

int mxidx=0;
int lp[1000006] = {0};
int a[100005];

typedef struct Node{
    vector<pair<int, int> > v;
} node;

node stree[4*100005];

void seive(){
    long long i, j;
    for(i=2; i<=1000000; i+=2)
        lp[i] = 2;
    for(i=3; i<=1000000; i+=2){
        if(!lp[i]){
            lp[i] = i;
            for(j=2; i*j <= 1000000; j++){
                if(!lp[i*j])
                    lp[i*j] = i;
            }
        }
    }
}

vector<pair<int, int> > calculate(int idx){
    vector<pair<int, int> > v;
    int ele = a[idx];

    while(ele >1){
        int lpf = lp[ele];
        int exp = 0;
        while(lp[ele] == lpf){
            exp++;
            ele/=lpf;
        }
        v.push_back(make_pair(lpf, exp));
    }
    return v;
}

vector<pair<int, int> > Merge(vector<pair<int, int> >&a, vector<pair<int, int> >&b){
    vector<pair<int, int> > v;
    int i=0, j=0;
    int n = a.size(), m=b.size();

    while(i<n && j<m){
        if(a[i].first == b[j].first){
            v.push_back(make_pair(a[i].first, a[i].second + b[j].second));
            i++;
            j++;
        } else if(a[i].first < b[j].first){
            v.push_back(make_pair(a[i].first, a[i].second));
            i++;
        } else{
            v.push_back(make_pair(b[j].first, b[j].second));
            j++;
        }
    }

    while(i<n){
        v.push_back(make_pair(a[i].first, a[i].second));
        i++;
    }
    while(j<m){
        v.push_back(make_pair(b[j].first, b[j].second));
        j++;
    }
    return v;
}

void build(int idx, int lb, int ub){
    if(lb == ub){
        stree[idx].v = calculate(lb);
        mxidx = max(mxidx, idx);
        return;
    }
    build(2*idx, lb, (lb+ub)/2);
    build(2*idx+1, (lb+ub)/2 + 1, ub);

    stree[idx].v = Merge(stree[2*idx].v, stree[2*idx + 1].v);
}

int upperbound(int idx, int lb, int ub, int x){
    if(lb > ub)
        return -1;
    int mid = (lb+ub)/2;
    if(stree[idx].v[mid].first == x)
        return mid;

    if (mid > 0 && stree[idx].v[mid-1].first <= x && x < stree[idx].v[mid].first)
        return mid-1;

    if (x < stree[idx].v[mid].first)
        return upperbound(idx, lb, mid-1, x);
    return upperbound(idx, mid+1, ub, x);
}

int query(int idx, int lb, int ub, int l, int r, int x, int y){
    if(lb > r || ub<l || lb > ub)
        return 0;
    if(lb>=l && ub<=r){
        int ans = 0;
        /*for(int i=0; i<stree[idx].v.size() && stree[idx].v[i].first <= y; i++){
            ans += stree[idx].v[i].first >= x ? stree[idx].v[i].second : 0;
        }*/
        int ub = upperbound(idx, 0, stree[idx].v.size()-1, y);
        if(ub != -1){
            ans += stree[idx].v[ub].second;
        }

        int lb = upperbound(idx, 0, stree[idx].v.size()-1, x);
        if(lb != -1){
            if(stree[idx].v[lb].first == x)
                ans -= lb-1 >=0 ? stree[idx].v[lb-1].second : 0;
            else
                ans -= stree[idx].v[lb].second;
        }

        return ans;
    }
    return query(2*idx, lb, (lb+ub)/2, l, r, x, y) +
            query(2*idx+1, 1+(lb+ub)/2, ub, l, r, x, y);
}

void init(){
    for(int i=0; i<=mxidx; i++){
        for(int j=1; j<stree[i].v.size(); j++){
            stree[i].v[j].second += stree[i].v[j-1].second;
        }
        stree[i].v.push_back(make_pair(1000006, 0));
    }
}

int main(){

    seive();
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    build(1, 0, n-1);
    init();
    int q;
    scanf("%d",&q);
    while(q--){
        int l, r, x, y;
        scanf("%d%d%d%d",&l,&r,&x,&y);
        printf("%d\n",query(1, 0, n-1, l-1, r-1, x, y));
    }

    return 0;
}
