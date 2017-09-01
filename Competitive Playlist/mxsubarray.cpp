#include<bits/stdc++.h>
using namespace std;
int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
int dp[20];
int maxSubarray(int n){

    dp[0] = a[0];
    for(int j=1; j<n; j++){
        dp[j] = max(dp[j-1] + a[j-1], a[j-1]);
    }

    int res = dp[0];
    for(int j=1; j<n; j++){
        printf("%d ",dp[j]);
        res = max(res, dp[j]);
    }
    printf("\n");
    return res;
}
int main(){

    printf("%d\n",maxSubarray(9));
}
