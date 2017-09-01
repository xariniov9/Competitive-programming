#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d",&n);
    int ans =0;
    for(int i=1; i*i <= n; i++){
        for(int j=i; i*j <= n; j++){
            ans++;
        }
    }
    printf("%d\n",ans);
}
