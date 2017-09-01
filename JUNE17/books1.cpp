#include<bits/stdc++.h>

using namespace std;
int k, m;

long long book[1000];

int ok(long long pg){
    long long curr = 0;
    int cnt=1;
    for(int i=0; i<m; i++){
        if(book[i] > pg)
            cnt = 1000000;
        curr += book[i];
        if(curr > pg){
            cnt++;
            curr=book[i];
        }
    }
    return cnt <= k;
}
void print(int idx, long long s,int tk) {
  long long t = 0;
  int i;
  for(i = idx; i >= 0;i--) {
    if(t + book[i] > s || i+1 == tk-1) {
      print(i,s,tk-1);
      break;
    }
    t += book[i];
  }
  if(i >= 0) printf("/ ");
  for(i++;i <= idx;i++) {
    printf("%lld",book[i]);
    if(i != m-1) printf(" ");
  }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&k);
        long long lb =0; long long ub = (long long)500 * 10000001;
        long long ans;

        for(int i=0; i<m; i++){
            scanf("%lld",&book[i]);
            ub += book[i];
        }

        while(lb < ub){
            long long mid = (lb+ub)/2;
            if(!ok(mid)){
                //ans = mid;
                lb = mid + 1;
            } else
                ub = mid;
        }
        //printf("ans %lld\n",ub);
        print(m-1, ub, k);
        printf("\n");
    }
    return 0;
}
