#include<bits/stdc++.h>

using namespace std;

int a[20006];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, k;
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a, a+n);
        int ans = 1e9+5;
        for(int i=0; i+k-1 < n; i++){
            ans = min(ans, a[i+k-1] - a[i]);
            if(ans == 0)
                break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
