#include<bits/stdc++.h>

using namespace std;

char S[505], T[505];
int main(){
    scanf("%s %s",S, T);

    while(S[0] != '*' && T[0] != '*'){

        int n = strlen(S);
        int ans = 0;
        for(int i=0; i<n;){
            if(S[i] != T[i]){
                int curr = i;
                while(i<n && (S[i] == S[i+1] || S[i] != T[i]))
                    i++;
                ans += (i-curr + 1);
            }

        }


        scanf("%s %s",S, T);
    }


    return 0;
}
