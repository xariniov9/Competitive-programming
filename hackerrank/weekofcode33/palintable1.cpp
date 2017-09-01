#include<bits/stdc++.h>

using namespace std;

int N, M;
map<int, map<int, map<int, map<int, int> > > > dp;

int **afirst;
int **asecond;

inline int sum(int li, int lj, int ri, int rj){
    return asecond[ri][rj] + asecond[li-1][lj-1] - asecond[ri][lj-1] - asecond[li-1][rj];
}
inline int Size(int li, int lj, int ri, int rj){
    return (rj - lj + 1) * (ri - li + 1);
}

inline int Mask(int li, int lj, int ri, int rj){
    return afirst[ri][rj] ^ afirst[li-1][lj-1] ^ afirst[ri][lj-1] ^ afirst[li-1][rj];
}
int palin(int li, int lj, int ri, int rj){
    int o=0, s=Size(li, lj, ri, rj), nz=0, z = sum(li, lj, ri, rj);
    nz = s - z;
    o = __builtin_popcount(Mask(li, lj, ri, rj));
    if(s-nz == s)
        return 1;
    if(nz==0 && s-nz == 1)
        return 1;
    if(nz < 2 && s-nz > 0)
        return 1;
    if(nz==1 && s-nz == 0)
        return 1;
    if(s%2 == 1){
        return o<=1 ? s : 0;
    }
    return o==0 ? s: 0;
}

int anss=0;
vector<int> ret(4);
map<int, map<int, map<int, map<int, int> > > >::iterator itr;



int solve(int li, int lj, int ri, int rj){
    if(li > N || lj > M || ri<=0 || rj <= 0 || li > ri || lj > rj)
        return 0;
    if(Size(li, lj, ri, rj) <= anss)
        return anss;

    int x=0;
    if(x = palin(li, lj, ri, rj)){
        if(x){
           if(x > anss){
                anss = x;
                ret[0] = li-1;
                ret[1] = lj-1;
                ret[2] = ri-1;
                ret[3] = rj-1;
           }
           return x;
        }
    }
    if(dp[li][lj][ri].find(rj) != dp[li][lj][ri].end())
        return dp[li][lj][ri][rj];
    int ans = 0;
    // l is stable..
    ans = max(ans, solve(li, lj, ri-1, rj)); //r moved up
    ans = max(ans, solve(li, lj, ri, rj-1)); //r moved left

    // l moved left
    ans = max(ans, solve(li, lj+1, ri, rj)); // r stable
    ans = max(ans, solve(li, lj+1, ri-1, rj)); //r moved up
    ans = max(ans, solve(li, lj+1, ri, rj-1)); //r moved left

    // l moved down
    ans = max(ans, solve(li+1, lj, ri, rj)); // r stable
    ans = max(ans, solve(li+1, lj, ri-1, rj)); //r moved up
    ans = max(ans, solve(li+1, lj, ri, rj-1)); //r moved left

    return dp[li][lj][ri][rj] = ans;
}

int main(){
    int n, m;
    int x;
    scanf("%d%d",&n,&m);
    //n=1000; m= 100;
    afirst = new int*[n+1];
    asecond = new int*[n+1];
    for(int i=0; i<=n; i++){
        afirst[i] = new int[m+1];
        asecond[i] = new int[m+1];
    }

    N=n; M=m;
    anss = 0;
    for(int i=0; i<=n; i++)
        afirst[i][0] = asecond[i][0] = 0;
    for(int i=1; i<=m; i++)
        afirst[0][i] = asecond[0][i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d",&x);

            afirst[i][j] = (1<<x);
            if(x==0)
                asecond[i][j] = 1;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            asecond[i][j] += asecond[i-1][j] + asecond[i][j-1] - asecond[i-1][j-1];
            afirst[i][j] ^= afirst[i-1][j] ^ afirst[i][j-1] ^ afirst[i-1][j-1];
        }
    }
    int ans = solve(1, 1, n, m);
    printf("%d\n",ans);
    if(ans > 1)
        printf("%d %d %d %d\n", ret[0], ret[1], ret[2], ret[3]);
    else
        printf("0 0 0 0\n");
    return 0;
}

