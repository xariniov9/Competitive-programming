#include<bits/stdc++.h>

using namespace std;

typedef struct box{
    int l, b, h;
} Box;

int n;
Box B[180];


void makeComb(int i, int l, int b, int h){
    B[i].l = max(l,b); B[i].b = min(l,b); B[i++].h = h;
    //B[i].l = b; B[i].b = l; B[i++].h = h;
    B[i].l = max(h, b); B[i].b = min(h, b); B[i++].h = l;
    //B[i].l = h; B[i].b = b; B[i++].h = l;
    B[i].l = max(l,h); B[i].b = min(l,h); B[i++].h = b;
    //B[i].l = h; B[i].b = l; B[i++].h = b;
}

int comp(const void * A, const void * B){
    int A1 = ((Box *)A)->l * ((Box *)A)->b;
    int A2 = ((Box *)B)->l * ((Box *)B)->b;

    return A2-A1;
}

int dp[6 * 31];

int solve(int idx){
    if(idx == n-1)
        return B[idx].h;
    if(dp[idx] != -1)
        return dp[idx];
    int ans = 0;
    for(int i=idx+1; i<n; i++){
        if(B[i].l < B[idx].l && B[i].b < B[idx].b)
            ans = max(ans, B[idx].h + solve(i));
    }
    return dp[idx] = max(B[idx].h, ans);
}

int main(){

    int l, b, h, itr=0;
    scanf("%d",&n);
    while(n!= 0){
        itr = 0;
        for(int i=0; i<n; i++){
            scanf("%d%d%d",&l,&b,&h);
            makeComb(itr, l, b, h);
            itr+=3;
        }
        for(int i=0; i<=itr; i++)
            dp[i] = -1;
        qsort(B, itr, sizeof(Box), comp);
        n = itr;
        printf("%d\n",solve(0));
        scanf("%d",&n);
    }
    return 0;
}
