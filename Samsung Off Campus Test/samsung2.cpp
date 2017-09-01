#include<bits/stdc++.h>

#define MOD 1000000007

using namespace std;

long long stree[4 * 100005];
int a[100005];

void multiply(long long F[2][2], long long M[2][2]);

void power(long long F[2][2], int n);

void build(int idx, int l, int r){
    if(l == r){
        stree[idx] = a[l];
        return;
    }
    build(2*idx, l, (l+r)/2);
    build(2*idx+1, 1+(l+r)/2, r);

    stree[idx] = __gcd(stree[2*idx], stree[2*idx+1]);
}

int query(int idx, int l, int r, int x, int y){
    if(y<l || x>r || l>r)
        return -1;
    if(l>=x && r<=y)
        return stree[idx];
    int m = (l+r)/2;
    int lft = query(2*idx, l, m, x, y);
    int rgt = query(2*idx+1, m+1, r, x, y);
    if(lft != -1 && rgt != -1)
        return __gcd(lft, rgt);
    return max(lft, rgt);
}


void power(long long F[2][2], int n){
  if( n == 0 || n == 1)
      return;
  long long M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

void multiply(long long F[2][2], long long M[2][2]){
  long long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long long z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
  F[0][0] = x % MOD;
  F[0][1] = y % MOD;
  F[1][0] = z % MOD;
  F[1][1] = w % MOD;
}
long long fib(int n){
  long long F[2][2] = {{1,1},{1,0}};
  if (n == 0)    return 0;
  power(F, n-1);
  return F[0][0] % MOD;
}
int main(){
    int n, q;
    scanf("%d%d",&n,&q);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    build(1, 0, n-1);
    while(q--){
        int l, r;
        scanf("%d%d",&l,&r);
        int ans = query(1, 0, n-1, l-1, r-1);
        long long res = fib(ans) % MOD;
        printf("%lld\n",res);
    }
    return 0;
}
