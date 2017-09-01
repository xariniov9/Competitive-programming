#include<bits/stdc++.h>

using namespace std;

char str[7000], rev[7000];

int dp[6105][6105];
int n1;

int lcs(int i, int j){
    if(i==n1 || j==n1)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(str[i] == rev[j]){
        return dp[i][j] = 1 + lcs(i+1, j+1);
    }
    int ans = max(lcs(i+1, j), lcs(i, j+1));
    return dp[i][j] = ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        n1 = strlen(str);
        for(int i=0; i<n1; i++){
            rev[i] = str[n1-i-1];
        }
        rev[n1] = '\0';
        for(int i=0; i<=n1; i++)
            for(int j=0; j<=n1; j++)
                dp[i][j] = -1;
        int ls = lcs(0, 0);
        printf("%d\n",n1-ls);
    }
    return 0;
}
