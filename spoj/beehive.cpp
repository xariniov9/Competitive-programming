#include<bits/stdc++.h>

int main(){

    int n;
    scanf("%d",&n);
    while(n!=-1){
        int i=1;
        n--;
        while(n>0){
            n-=(i*6);
            i++;
        }
        if(n==0)
            printf("Y\n");
        else
            printf("N\n");
        scanf("%d",&n);
    }
    return 0;
}
