#include<bits/stdc++.h>

using namespace std;

long long a[100005];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int flag=0;
        long long n, sum=0;
        scanf("%lld",&n);
        for(int i=0; i<n; i++)
            scanf("%lld",&a[i]);
        sort(a, a+n);
        long long pos = n;
        for(int i=n-1; i>=0; i--){
            if(a[i] >= 0){
                sum += a[i];
                pos = i;
            }else break;
        }
        long long cnt = n-pos;
        for(int i=pos-1; i>=0; i--){
            if((sum + a[i])*(cnt+1) >= sum * cnt ){
                sum += a[i];
                cnt++;
                pos=i;
            }
            else{
                //pos = i;
                break;
            }
        }
        sum  = sum * cnt;
        for(int i=pos-1; i>=0; i--){
            sum += a[i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}
