#include<bits/stdc++.h>

using namespace std;

int N, M;
map<int, map<int, vector<int> > > a;
map<int, map<int, map<int, map<int, int> > > > dp;


int sum(int li, int lj, int ri, int rj, int dig){
    return a[ri][rj][dig] + a[li-1][lj-1][dig] - a[ri][lj-1][dig] - a[li-1][rj][dig];
}

int palin(int li, int lj, int ri, int rj){

    vector<int> digs;
    for(int i=0; i<10; i++)
        digs.push_back(sum(li, lj, ri, rj, i));
    int e=0, o=0, s=0, nz=0;
    for(int i=0; i<=10; i++){
        e += digs[i]%2==0 ? 1 : 0;
        o += digs[i]%2==0 ? 0 : 1;
        if(digs[i] > 0 && i!=0)
            nz+=digs[i];
        s += digs[i];
    }
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

int Size(int li, int lj, int ri, int rj){
    return (rj - lj + 1) * (ri - li + 1);

}

int solve(int li, int lj, int ri, int rj){
    if(li > N || lj > M || ri<=0 || rj <= 0 || li > ri || lj > rj)
        return 0;
    if(Size(li, lj, ri, rj) <= anss)
        return anss;
    if(dp[li][lj][ri].find(rj) != dp[li][lj][ri].end())
        return dp[li][lj][ri][rj];
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
           return dp[li][lj][ri][rj] = x;
        }
    }

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
    //n=10; m= 100;
    N=n; M=m;
    anss = 0;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=9; j++)
            a[i][0].push_back(0);
    for(int i=1; i<=m; i++)
        for(int j=0; j<=9; j++)
            a[0][i].push_back(0);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=0; k<=9; k++)
                a[i][j].push_back(0);
            scanf("%d",&x);
            //x=0;
            a[i][j][x] = 1;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=0; k<=9; k++){
                a[i][j][k] += a[i-1][j][k] + a[i][j-1][k] - a[i-1][j-1][k];
            }
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
