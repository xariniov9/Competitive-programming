#include<bits/stdc++.h>

using namespace std;
char s1[20], s2[10];
int n;
int c1[26], c2[26];
int solve(int idx){
    if(idx == n){
        int d1=0, d2=0;
        for(int i=0; i<26; i++){
            if(c1[i])   d1++;
            if(c2[i])   d2++;
        }
        //printf("max : %d\n",max(d1, d2));
        return max(d1, d2);
    }

    c1[s1[idx]-'a']++;
    c2[s2[idx]-'a']++;
    int ans = solve(idx+1);
    c1[s1[idx]-'a']--;
    c2[s2[idx]-'a']--;

    c1[s2[idx]-'a']++;
    c2[s1[idx]-'a']++;
    ans = min(ans, solve(idx+1));
    c1[s2[idx]-'a']--;
    c2[s1[idx]-'a']--;
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s\n%s",s1,s2);
        for(int i=0; i<26; i++)
            c1[i] = c2[i] = 0;
        printf("%d\n",solve(0));
    }
    return 0;
}
