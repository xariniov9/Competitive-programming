#include<bits/stdc++.h>

using namespace std;

int lpfact[10001] = {0};

void seive(){
    for(int i=2; i<=10000; i+=2){
        lpfact[i] = 2;
    }
    for(int i=3; i<=10000; i+=2){
        if(!lpfact[i]){
            lpfact[i] = i;
            for(int j=2; j*i<=10000; j++)
                if(!lpfact[i*j])
                    lpfact[j*i] = i;
        }
    }
   /* for(int i=2; i<=100; i++){
        if(lpfact[i] == i)
            printf("%d ",i);
    }
    printf("\n");*/
}

int numP(int n){
    int cnt=0;
    while(n > 1){
        int lpf = lpfact[n];
        cnt++;
        while(lpfact[n] == lpf)
            n/=lpfact[n];
    }
    return cnt;
}
int main(){
    seive();
    int t;
    scanf("%d",&t);
    while(t--){
        int n, cnt=0;
        scanf("%d",&n);
        for(int i=30; i<=10000; i++){
            if(numP(i) >= 3)
                cnt++;
            if(cnt==n){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
