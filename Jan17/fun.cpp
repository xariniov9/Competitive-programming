#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<assert.h>
using namespace std;

char str[500];
int y, m, n, x;


long long max(long long a, long long b){
    return a>b ? a : b;
}

int modThree;
bool cmp(const pair<int, long long>&i, const pair<int, long long>&j){
    if(i.second == j.second)
        return i.first < j.first;
    return i.second > j.second;
}

long long ANS;

vector< vector<map<long long, long long> > > dp(305, vector<map<long long, long long> >(305));

long long solveFinal1(int idx, int su, long long gcdSf){

    if(gcdSf <= ANS)
        return ANS;
    if(idx > n || su>y || (x-su > n-idx))
        return 0;
    if(m*(y-su) < n-idx )
        return 0;
    if(idx == n){
        if(su >= x && su <= y)
            return gcdSf;
        return 0;
    }
    long long x;
    if(x = dp[idx][su][gcdSf])
        return x;
    long long currNum = 0;
    vector<pair<int, long long> > nums;
    for(int i=0; i<m && (idx+i)<n; i++){
        currNum = currNum * 10 + (str[idx+i] - '0');
        if(currNum > ANS){
            long long ss = __gcd(currNum, gcdSf);
            if(ss > ANS)// && ss >1)
                nums.push_back(make_pair(i, ss));
        }
    }
    sort(nums.begin(), nums.end(), cmp);
    int it = nums.size();

    for(int i=0; i<it; i++){
        if(i>0 && idx>1)
            break;

        ANS=max(ANS, solveFinal1(idx+nums[i].first+1, su+1, nums[i].second));
    }
    return (dp[idx][su][gcdSf] = ANS);
}

int main(){
    int t, three;

    scanf("%d",&t);
    while(t--){
        ANS=-1;
        scanf("%d",&n);
        scanf("%s",str);
        scanf("%d%d%d",&m,&x,&y);
        for(int i=0; i<=n+1; i++)
            for(int j=0; j<=n+1; j++)
                dp[i][j].clear();
        x++; y++;
        solveFinal1(0, 0, 0);
        //if(ANS <= 1)
            //ANS = 1;
        printf("%lld\n",ANS);
       // assert(ANS<=1000000);
    }
    return 0;
}
