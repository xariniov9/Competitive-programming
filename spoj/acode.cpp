#include<bits/stdc++.h>

using namespace std;
int n;
char str[5005];
long long dp[5005];
void initDP(){
    for(int i=0; i<=n+1; i++)
        dp[i] = -1;
}

long long solve(int idx){
    if(idx == n)
        return 1;
    if(dp[idx] != -1) return dp[idx];

    long long ans = 0;
    int f=0, s=0;

    f = str[idx] - '0';
    if(idx < n-1 && str[idx] != '0')s = (str[idx] - '0') * 10 + (str[idx+1] - '0');

    if(f>=1 && f<=26)
        ans = solve(idx + 1);
    if(s >= 1 && s <= 26)
        ans += solve(idx+2);
    return dp[idx] = ans;
}


int main(){
    scanf("%s",str);
    while(str[0] != '0'){
        n=strlen(str);
        initDP();
        long long ans = solve(0);
        printf("%lld\n",ans);
        scanf("%s",str);
    }
    return 0;
}
