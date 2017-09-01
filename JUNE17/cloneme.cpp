#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
    int xr;
    int x[20];
} node;


node Stree[4*100005];

void buildTree(int idx, int l, int r){
    if(l == r){
        Stree[idx].xr = a[l];
        for(int i=0; i<20; i++){
            if(a[l] & (1<<i))
                Streex[idx].x[i] = a[l];
            else
                Streex[idx].x[i] = 0;
        }
        return;
    }
    buildTree(2*idx, l, (l+r)/2);
    buildTree(2*idx+1, 1+ (1+r)/2, r);

    Stree[idx].xr = Stree[2*idx].xr ^ Stree[2*idx+1].xr;
    for(int i=0; i<20; i++)
        Streex[idx].x[i] = Streex[2*idx].x[i] ^ Streex[2*idx+1].x[i]
}

void query(int idx, int l, int r, int x, int y, int bit){
    if(l>y || r<x)
        return 0;
    if(l>=x && r<=y){
        if(dig == -1)
            return Stree[idx].xr;
        return Stree[idx].x[dig];
    }
    return query(2*idx, l, (l+r)/2, x, y, bit) ^
            query(2*idx+1, 1+(l+r)/2, x, y, bit);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(Stree, 0, sizeof Stree);
        int n, q;
        scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        buildTree(1, 0, n-1);
        while(q--)


    }

}
