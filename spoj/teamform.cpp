#include<bits/stdc++.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m, u, v;
        scanf("%d%d",&n,&m);
        if(n%2==0)
            printf("yes\n");
        else
            printf("no\n");
        for(int i=0; i<m; i++)
            scanf("%d %d",&u,&v);
    }
    return 0;
}
