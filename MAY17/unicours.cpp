#include<bits/stdc++.h>

using namespace std;

//int a[100005];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, ans=0, x;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&x);
            ans = max(ans, x);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
