#include<cstdio>
#include<iostream>
using namespace std;

long long a[100005];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, flag=0;
        long long x, sum=0;
        long long mn = (long long)1e9+5;

        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%lld",&x);
            a[i] = x;
            sum += x;
            mn = min(mn, x);
        }
        for(int i =0; i<n; i++){
            if(a[i] == mn+1)
                flag = 1;
        }
        if(flag){
            for(int i=0; i<n-1; i++){
                sum -= mn;
                mn++;
            }
            printf("%lld\n",sum);
        }
        else
            printf("%lld\n",mn);
    }
    return 0;
}
