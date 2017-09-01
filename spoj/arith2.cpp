#include<bits/stdc++.h>

#define plus 1
#define minus -1
#define mult 2
#define div 3


long long getNum(char * str){
    long long ret = 0;
    for(int i=0; i<strlen(str); i++)
        ret = ret * 10 + (str[i] - '0');
    return ret;
}

int getopr(char * str){
    if(str[0] == '+')
        return plus;
    else if(str[0] == '-')
        return minus;
    else if(str[0] == '*')
        return mult;
    else return div;
}

int main(){
   int t;
   scanf("%d",&t);
   char str[30];

   while(t--){
        long long ans = 0;
        int prevo = plus;
        scanf("%s", str);
        while(str[0] != '='){
            if(str[0] >= '0' && str[0] <= '9'){
                if(prevo == plus)
                    ans += getNum(str);
                else if(prevo == minus)
                    ans -= getNum(str);
                else if(prevo == mult)
                    ans *= getNum(str);
                else
                    ans /= getNum(str);
            }
            else
                prevo = getopr(str);
            scanf("%s",str);
        }
        printf("%lld\n",ans);
   }
    return 0;
}
