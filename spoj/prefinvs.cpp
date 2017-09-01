#include<bits/stdc++.h>

char str[100005];

int curS(int opr, int idx){
    if(str[idx] == '0' && opr % 2 == 0){
        return 0;
    } else if( str[idx] == '1' && opr %2 == 1)
        return 0;
    return 1;
}

int main(){
    scanf("%s",str);
    int opr = 0;
    for(int i=strlen(str)-1; i>=0; i--){
        if(curS(opr, i) == 1)
            opr++;
    }
    printf("%d\n",opr);
}
