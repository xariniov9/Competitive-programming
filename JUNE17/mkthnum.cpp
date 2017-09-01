#include<bits/stdc++.h>

using namespace std;

struct node{
    node * left;
    node * right;
    int count;

public:
    node(node * l, node * r, int c){
        left = l; right=r; count=c;
    }

    node * insert(int l, int r, int val){
        if(val>=l && val < r){
            if(l+1 == r){
                node * null = new node(NULL, NULL, 0);
                null->left = null;
                null->right = null;
                return new node(null, null, this->count +1);
            }
            int m = (l+r)/2;

            return new node(this->left->insert(l, m, val),
                        this->right->insert(m, r, val), this->count+1);
        }
        return this;
    }
};

int query(node * r, node * l, int lb, int ub, int k){
    if(lb+1 == ub){
        return lb;
    }
    int m = (lb+ub)/2;
    int count = r->left->count - l->left->count;
    if(count >= k){
        return query(r->left, l->left, lb, m, k);
    }
    return query(r->right, l->right, m, ub, k-count);
}

int a[123456];
node * nodes[123456];

int main(){
    int n, m;
    int lim = 0;
    scanf("%d%d", &n, &m);
    vector<int> v;
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    vector<int>::iterator it=unique(v.begin(), v.end());
    v.resize(distance(v.begin(), it));
    for(int i=0; i<n; i++){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        lim = max(lim, a[i]);
    }
    lim++;
    node * null = new node(NULL, NULL, 0);
    null->left = null;
    null->right = null;

    nodes[0] = null->insert(0, lim, a[0]);
    for(int i=1; i<n; i++){
        nodes[i] = nodes[i-1]->insert(0, lim, a[i]);
    }

    while(m--){
        int U, V, K;
        scanf("%d%d%d", &U, &V, &K);
        U--; V--;
        node * r = nodes[V];
        node * l = U==0?null : nodes[U-1];
        int ans = query(r, l, 0, lim, K);
        printf("%d\n",v[ans]);

    }

    return 0;
}
