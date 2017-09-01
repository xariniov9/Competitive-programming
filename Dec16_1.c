
#include<stdio.h>

int a[] = {0, 4, 5, 6, 1, 2, 3, 8, 7};

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);

        int cnum = n%8;
        if(cnum == 0)
            cnum = 8;

        int ans = n + (a[cnum] - cnum);
        if(cnum == 3 || cnum == 6)
            printf("%dUB\n",ans);
        if(cnum == 2 || cnum == 5){
            printf("%dMB\n",ans);
        }
        if(cnum == 1 || cnum == 4)
            printf("%dLB\n",ans);
        if(cnum == 7)
            printf("%dSU\n",ans);
        if(cnum == 8)
            printf("%dSL\n",ans);

    }
    return 0;
}
