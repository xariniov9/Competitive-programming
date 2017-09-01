#include<bits/stdc++.h>

using namespace std;

int E[1000005] = {0};
int lp[1000005] = {0};

int seive(){
    E[0] = E[1] = 1;
    long long i, j;
    for(i=2; i<=1000000; i++){
        if(!lp[i]){
            E[i] = i-1;
            lp[i] = i;
            for(j=2; i*j<=1000000; j++){
                E[i] = E[i] *
            }
        }
    }
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n",E[n]);
    }
    return 0;
}
