#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
int n2;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        n2 = m;
        for(int i=0; i<m; i++)
            scanf("%d",&b[i]);
        sort(b, b+m);
        int ans = abs(a[0] - b[0]);
        for(int i=0; i<n; i++){
            int x = lower_bound(b, b+m, a[i]) - b;
            if(x < m && x > 0){
                ans = min(ans, min(abs(a[i] - b[x]), abs(a[i] - b[x-1]) ));
            }
            else if(x == m)
                ans = min(ans, abs(a[i] - b[m-1]));
            else
                ans = min(ans, abs(a[i] - b[0]));
           // ans = min(ans, binarySearch(a[i]));
        }
        printf("%d\n",ans);
    }
    return 0;
}
