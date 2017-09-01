#include<bits/stdc++.h>

long long a[1000005];
long long stk[1000005];

int main(){
    int n;
    int tos = -1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%lld",&a[i]);
    long long ans = 0;

    stk[++tos] = a[0];

    for(int i=1; i<n; i++){
        while(tos > -1){
            if(a[i] >= stk[tos]){
                if(tos == 0)
                    ans += a[i];
                else{
                    if(a[i] > stk[tos-1])
                        ans += stk[tos-1];
                    else
                        ans += a[i];
                }
                tos--;
            }else break;

        }
        stk[++tos] = a[i];
    }
    for(int i=0; i<tos; i++)
        ans += stk[i];
    printf("%lld\n",ans);

}
