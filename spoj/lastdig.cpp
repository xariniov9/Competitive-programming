#include<bits/stdc++.h>


char str[1005];

int Pow(int a, long long n){
    if(n==0)
        return 1;
    if(n%2){
        return (((a%10) * (Pow((a*a)%10, n/2)%10))%10);
    }
    return Pow((a*a)%10, n/2)%10;
}
int main(){
    int t;
    long long p;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        scanf("%lld",&p);
        int dig = str[strlen(str)-1] - '0';
        int lastDig = Pow(dig, p);
        printf("%d\n",lastDig);
    }
    return 0;
}
