#include<bits/stdc++.h>

using namespace std;

char str[2005];

int solve(){
    int n = strlen(str);
    int ans = 0;
    int i=0;
    while(i<n){
        if(str[i] == '1'){
            int j = i+1;
            while(j<n && str[j] == '0')
                j++;
            if(j<n && str[j] == '1' && j != i+1){
                ans++;
            }
            i = j;
        } else
            i++;
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        printf("%d\n",solve());
    }
    return 0;
}
