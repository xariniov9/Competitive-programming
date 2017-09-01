#include<bits/stdc++.h>

using namespace std;
#define lim 10000000

int prime[10000000];
int lpfact[10000005] = {0};
int itr;

void seive(){
    itr=0;
    prime[itr++] = 2;
    long long i, j;
    for(i=2; i<=lim; i+=2)
        lpfact[i] = 2;
    for(i=3; i<=lim; i+=2){

        if(!lpfact[i]){
            lpfact[i] = i;
            prime[itr++] = i;
            for(j=2; i*j<=lim; j++){
                if(!lpfact[i*j]){
                    lpfact[i*j] = i;
                }
            }
        }
    }

    //printf("itr : %d\n",itr);

}

int main(){

    seive();
    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans = upper_bound(prime, prime+itr, n) -
                    lower_bound(prime, prime+itr, n-(n+1)/2+1);
        printf("%d\n",ans);
    }
    return 0;
}
