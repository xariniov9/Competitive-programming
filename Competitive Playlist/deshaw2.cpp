#include<bits/stdc++.h>
int xx, x, n;
int cand[100][205];
int vis[
long long solve(int idx){
    if(idx == n){
        return 1;
    }
    long long ans = 0;
    for(int i=0; i<num[idx]; i++){
        if(!vis[cand[idx][i]){
            vis[cand[idx][i]] = 1;
            ans += solve(idx+1);
            vis[cand[idx][i]] = 0;
        }
    }
    return ans;
}

int main(){


}
