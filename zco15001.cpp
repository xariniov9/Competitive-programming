#include<bits/stdc++.h>

using namespace std;

int a[305];

int solve(int l, int r){
    if(l>r)
        return 5000;
    if(l==r)
        return 1;
    if(dp[l][r] != -1)
        return dp[l][r];
    if(isPalin(l, r))
        return dp[l][r] = 1;
    return 1+ min(solve(l+1, r), solve(l, r-1));
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

}
