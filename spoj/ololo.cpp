#include<bits/stdc++.h>

int main(){

    int n;
    scanf("%d",&n);
    int v;
    int ans = 0;
    for(int i=0; i<n; i++){
        scanf("%d",&v);
        ans = ans ^ v;
    }
    printf("%d\n",ans);
    return 0;
}
