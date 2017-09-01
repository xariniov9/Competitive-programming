#include<bits/stdc++.h>

using namespace std;

int a[100005];

int main(){
    int n, k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    sort(a, a+n);
    long long ans = 0;
    for(int i=0; i<n; i++){
        if(a[i] <= k)
            ans += (long long)(upper_bound(a+i+1, a+n, k-a[i]-1) - (a + i + 1));
    }
    printf("%lld\n",ans);
    return 0;
}
