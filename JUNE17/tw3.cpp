#include<bits/stdc++.h>

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int a, b;
        scanf("%d%d",&a,&b);
        if(a==1 && b==1){
            printf("Draw\n");
        } else if(a==1){
            printf("Chandu Don\n");
        } else if(b == 1){
            printf("Arjit\n");
        } else{
            if(a<b){
                printf("Chandu Don\n");
            } else
                printf("Arjit\n");
        }
    }
    return 0;
}
