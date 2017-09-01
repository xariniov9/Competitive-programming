#include<bits/stdc++.h>

int prime[3005];
int lpfact[100000] = {0};

void seive(){
    int itr=1;
    prime[itr++] = 2;

    for(int i=2; i<=100000; i+=2)
        lpfact[i] = 2;
    for(int i=3; i<=100000; i++){
        if(itr == 3001)
            break;
        if(!lpfact[i]){
            lpfact[i] = i;
            prime[itr++] = i;
            for(int j=2; i*j<=100000; j++){
                if(!lpfact[i*j]){
                    lpfact[i*j] = i;
                }
            }
        }
    }

    /*for(int i=1; i<=50; i++)
        printf("%d ",prime[i]);
    printf("\n");

    printf("itr : %d\n",itr);*/

}

int main(){

    int n;
    scanf("%d",&n);
    seive();
    printf("%d\n",prime[n]);
    return 0;
}
