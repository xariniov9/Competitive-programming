#include<bits/stdc++.h>

// 831143535290875991/1000000000000000000

long long dp[19][2][10][2][2];
char num[20];
int numDig;

long long solve(int idx, int mask, int dig, int up, int started){
    if(idx == numDig){
        return (mask != 0) ? 1 : 0;
    }
    if(dp[idx][mask][dig][up][started] != -1)
        return dp[idx][mask][dig][up][started];
    long long ans = 0;
    int i = 0;
    if(up){
        int newMask;
        for(i; i<num[idx]-'0'; i++){
            if(i==0 && dig == 0) newMask = started!=0 ? 1:0;
            else newMask = (mask || (i == dig));
            ans += solve(idx+1, newMask, dig, 0, started || (i!=0));
        }

         if(num[idx] - '0' ==0 && dig == 0) newMask = started!=0 ? 1:0;
         else newMask = (mask || (num[idx] - '0' == dig));
         ans += solve(idx+1, newMask, dig, 1, started || (num[idx] - '0' !=0));
    } else{
        for(i; i<=9; i++){
            int newMask;
            if(i==0 && dig == 0) newMask = started!=0 ? 1:0;
            else newMask = (mask || (i == dig));
            ans += solve(idx+1, newMask, dig, 0, started || (i!=0));
        }
    }
    return dp[idx][mask][dig][up][started] = ans;
}

long long calc(){
    long long ans = 0;
    for(int j=0; j<=9; j++){
        ans += solve(0, 0, j,1, 0);
    }
    return ans;
}

long long toNum(){
    long long ans = 0;
    for(int i=0; i<strlen(num); i++){
        ans = (long long)ans * 10 + num[i] - '0';
    }
    return ans;
}

long long GCD(long long u, long long v) {
    while ( v != 0) {
        long long r = u % v;
        u = v;
        v = r;
    }
    return u;
}



int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",&num);
        numDig = strlen(num);
        memset(dp, -1, sizeof dp);
        long long denom = toNum();
        long long numr = calc();
        denom = denom * 10;

        //printf("before : %lld/%lld\n",numr, denom);

        long long gcd = GCD(numr, denom);
        printf("%lld/%lld\n",numr/gcd, denom/gcd);
    }
    return 0;
}
