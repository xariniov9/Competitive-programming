#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

char str[505];
int n, d;
int vis[505] = {0};

vector<map<string, int> > dp(505);

int solve(int idx, string s){
    if(idx == n-1){
        for(int i=0; i<n; i++)
            if(s[i] == 1)
                return 0;
        return 1;
    }
    if(dp[idx].find(s) != dp[idx].end())
        return dp[idx][s];
    int ans=0;
    if(str[idx]!='?'){
        if(idx-(str[idx]-'0') >= 0 && s[idx-str[idx]+'0'] == 1){
            s[idx-str[idx]+'0'] = 2;
            ans = solve(idx-str[idx]+'0', s)%MOD;
            s[idx-str[idx]+'0'] = 1;
        }
        if(idx+str[idx]-'0' < n && s[idx+str[idx]-'0'] == 1){
            s[idx+str[idx]-'0'] = 2;
            ans = (ans + solve(idx+str[idx]-'0', s) ) %MOD;
            s[idx+str[idx]-'0'] = 1;
        }
    } else {
        for(int i=1; i<=d; i++){
            if(idx + i < n && s[idx+i] == 1){
                s[idx+i] = 2;
                ans += solve(idx+i, s)%MOD;
                ans = ans % MOD;
                s[idx+i] = 1;
            }
        }
        for(int i=1; i<=d; i++){
            if(idx - i >= 0 && s[idx-i] == 1){
                s[idx-i] = 2;
                ans += solve(idx-i, s)%MOD;
                ans = ans % MOD;
                s[idx-i] = 1;
            }
        }
    }
    return dp[idx][s] = ans;
}

int main(){
    scanf("%s",str);
    n = strlen(str);
    string s(n, 1);
    scanf("%d",&d);
    s[0] = 2;
    printf("%d\n",solve(0, s));
    return 0;
}
