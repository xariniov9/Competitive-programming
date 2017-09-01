#include<bits/stdc++.h>
int n, k;
int a[1010];

void solve(){
    int it=0, j=0;
    for(int i=0; i<n-1; i++)
        if(a[i] < a[i+1])
            it=i;
    for(int i=it; i<n; i++)
        if(a[i] > a[it])
            j=i;
    int tmp = a[it];
    a[it] = a[j];
    a[j] = tmp;

    int i=it+1; j=n-1;
    while(i<j){
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++; j--;
    }

}

int main(){
    scanf("%d%d",&n,&k);
    while(k--){
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        solve();
        for(int i=0; i<n; i++)
            printf("%d ",a[i]);
        printf("\n");
    }

}
