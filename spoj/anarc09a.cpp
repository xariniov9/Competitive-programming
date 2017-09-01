#include<bits/stdc++.h>

using namespace std;
char str[2005];


int main(){
    int t=1;
    scanf("%s",str);
    while(str[0] != '-'){

        stack<int> stk;
        int cnt=0;
        for(int i=0; i<strlen(str); i++){
            if(str[i] == '{'){
                stk.push('{');
            } else{
                if(!stk.empty())
                    stk.pop();
                else{
                    cnt++;
                    stk.push('{');
                }
            }
        }
        int c2 = stk.size();
        cnt += c2/2;
        printf("%d. %d\n",t, cnt);
        t++;
        scanf("%s",str);
    }
    return 0;
}
