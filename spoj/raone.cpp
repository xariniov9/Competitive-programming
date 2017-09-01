#include<bits/stdc++.h>

using namespace std;

string str;

int dp[10][10][2][100][100];
int numDig;

int solve(int idx, int realidx, int tight, int e, int o){
    if(idx == numDig){
        return realidx % 2 ? ((e-o)==1 ? 1 : 0) : ((o-e) == 1 ? 1 : 0);
    }
    if(dp[idx][realidx][tight][e][o] != -1)
        return dp[idx][realidx][tight][e][o];
    int ans = 0;
    if(tight){
        for(int i=0; i<str[idx]-'0'; i++){
            int newRealidx = (realidx || (i!=0))?realidx+1:0;
            int newo = newRealidx == 0 ? 0 : ((newRealidx)%2 ? o+i: o);
            int newe = newRealidx == 0 ? 0 : ((newRealidx)%2 ?  e : e+i);
            ans += solve(idx+1, newRealidx, 0, newe, newo);
        }
        int newRealidx = (realidx>0 || (str[idx]-'0' !=0))?realidx+1:0;
        int newo = newRealidx == 0 ? 0 : ((newRealidx)%2 ? o+str[idx]-'0' : o);
        int newe = newRealidx == 0 ? 0 : ((newRealidx)%2 ?  e : e+str[idx]-'0');
        ans += solve(idx+1, newRealidx, 1, newe, newo);
    } else {
        for(int i=0; i<9; i++){
            int newRealidx = (realidx || (i!=0))?realidx+1:0;
            int newo = newRealidx == 0 ? 0 : ((newRealidx)%2 ?  o+i : o);
            int newe = newRealidx == 0 ? 0 : ((newRealidx)%2 ?  e : e+i);
            ans += solve(idx+1, newRealidx, 0, newe, newo);
        }
    }
    return dp[idx][realidx][tight][e][o] = ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a, b;
        int ans = 0;
        scanf("%d%d",&a,&b);
        a--;
        if(b>0){
            str = to_string(b);
            numDig = str.size();
            memset(dp, -1, sizeof dp);
            ans = solve(0, 0, 1, 0, 0);
        }
        if(a>0){
            str = to_string(a);
            numDig = str.size();
            memset(dp, -1, sizeof dp);
            ans -= solve(0, 0, 1, 0, 0);
        }
        printf("%d\n",ans);
    }
    return 0;
}
