#include<bits/stdc++.h>

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        char s[300];
        scanf("%s",s);
        int n = strlen(s);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!(s[i] == 'a' || s[i] == 'i' || s[i] == 'o' || s[i] == 'e' || s[i] == 'u')){
                ans++;
            }
        }
        printf("%d/%d\n",(ans-3),n);
    }
    return 0;
}
