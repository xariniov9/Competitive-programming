#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
       scanf("%d",&x);
        if(i+x >= n){
            printf("%d\n",i+1);
            break;
        }
    }
    return 0;
}
