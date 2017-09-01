#include<bits/stdc++.h>


int vis[2005][2005] = {0};

int cnt;
char str[1005];
void visit(int x, int y){
    if(vis[x][y])
        cnt++;
}

int main(){

    scanf("%s",str);
    while(str[0] != 'Q'){
        cnt=0;
        int x=1001, y=1001;
        for(int i=0; i<=2004; i++)
            for(int j=0; j<=2004; j++)
                vis[i][j] = 0;
        for(int i=0; str[i]!='Q'; i++){
            vis[x][y] = 1;
            if(str[i] == 'U'){
                x--;
            } else if(str[i] == 'D')
                x++;
            else if(str[i] == 'R')
                y++;
            else
                y--;
            visit(x, y);
        }
        printf("%d\n",cnt);
        scanf("%s",str);
    }
    return 0;
}
