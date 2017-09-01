#include<bits/stdc++.h>

long double e = 2.718281828459045;

int main(){
    long double n=1;
    int ans = 0;
    for(int i=0; i<20; i++){
        long double tmp = e * n;
        ans += (int)tmp;
        printf("%d ",ans);
        n+=1;
    }
    printf("\n");
    return 0;
}
