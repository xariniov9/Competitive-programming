#include<bits/stdc++.h>

int vis[33815] = {0};
int lck[3005];

void solve(){
    int itr = 0;

    for(int i=2; i<=33810; i++){
        if(!vis[i]){
            lck[itr++] = i;
            int cnt = 0;
            vis[i] =1;
            for(int j=i+1; j<=33810; j++){
                if(!vis[j])
                    cnt++;
                if(cnt == lck[itr-1]){
                    vis[j] = 1;
                    cnt = 0;
                }
            }
        }
    }
    //printf("itr : %d\n",itr);
}


int main(){

    int n=0;
    solve();
    scanf("%d",&n);
    while(n!=0){
        printf("%d\n",lck[n-1]);
        scanf("%d",&n);
    }
    return 0;
}
