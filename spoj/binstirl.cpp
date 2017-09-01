#include<bits/stdc++.h>

using namespace std;

int S[50][50] = {0};

void binst(){
    S[0][0] = 1;
    for(int i=1; i<50; i++){
        for(int j=1; j<50; j++){
            S[i][j] = (j*S[i-1][j] + S[i-1][j-1]) % 2;
            if(S[i][j])
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main(){

    //binst();
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m;
        scanf("%d %d",&n,&m);
        if(n==0 || m==0){
            if(n==0 && m==0)
                printf("1\n");
            else
                printf("0\n");
            continue;
        }
        if((n-m) & (m-1)/2)
            printf("0\n");
        else
            printf("1\n");

    }
    return 0;
}
