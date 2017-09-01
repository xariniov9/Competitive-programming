#include<bits/stdc++.h>
/*
1
99
1000000000000000000
669581781870842101

1
99 10000000
1673830

*/
char n1[20];
int n;

long long dp[20][2][11][11][2][2][2];

long long solve(int idx, int tight, int p2, int p1, int even, int odd, int started){
    if(idx == n){
        return even && odd;
    }
    if(dp[idx][tight][p2][p1][even][odd][started] != -1) return dp[idx][tight][p2][p1][even][odd][started];
    long long ans = 0;
    if(tight){
        for(int i=0; i<n1[idx] - '0'; i++){
           int newstarted = started || (i!=0);
           int newtight = 0; //
           int newp2 = p1;
           int newp1 = (newstarted != 0)?i : 10;
           int neweven = (even) || (newp1 == newp2 && (newp1!=10 && newp2 != 10));
           int newodd = (odd) || (p2 == newp1 &&(p2!=10 && newp1 != 10 ));

            ans += solve(idx+1, newtight, newp2, newp1, neweven, newodd, newstarted);
        }
        int newstarted = started || (n1[idx] - '0' !=0);
        int newtight = 1; //
        int newp2 = p1;
        int newp1 = (newstarted != 0)?n1[idx] - '0' : 10;
        int neweven = (even) || (newp1 == newp2 && (newp1!=10 && newp2 != 10));
        int newodd = (odd) || (p2 == newp1 &&(p2!=10 && newp1 !=10 ));
        ans += solve(idx+1, newtight, newp2, newp1, neweven, newodd, newstarted);       //on str[i]
    } else {
        for(int i=0; i<=9; i++){
           int newstarted = started || (i!=0);
           int newtight = 0; //
           int newp2 = p1;
           int newp1 = (newstarted != 0)?i : 10;
           int neweven = (even) || (newp1 == newp2 && (newp1!=10 && newp2 != 10));
           int newodd = (odd) || (p2 == newp1 &&(p2!=10 && newp1 !=10 ));

           ans +=  solve(idx+1, newtight, newp2, newp1, neweven, newodd, newstarted);
        }
    }
    return dp[idx][tight][p2][p1][even][odd][started] = ans;
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",n1);
        n = strlen(n1);
        memset(dp, -1, sizeof dp);
        long long ans = solve(0, 1, 10, 10, 0, 0, 0); //
        scanf("%s",n1);
        n = strlen(n1);
        memset(dp, -1, sizeof dp);
        long long ans1 = solve(0, 1, 10, 10, 0, 0, 0);

        printf("%lld\n",ans1 - ans);

    }
    return 0;
}
