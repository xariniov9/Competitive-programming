
#include<bits/stdc++.h>

using namespace std;

int a[100005];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0; i<2*n; i++){
            scanf("%d",&a[i]);
        }
        sort(a, a+(2*n));
        int i=0, j=2*n-1;
        printf("%d\n",a[n + n/2]);
        while(i < j){
            printf("%d %d ",a[i],a[j]);
            i++; j--;
        }
        printf("\n");
    }
    return 0;
}
