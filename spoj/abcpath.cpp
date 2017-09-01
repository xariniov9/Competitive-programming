#include<bits/stdc++.h>
using namespace std;
int h, w;
char str[100];
int a[100][100];
int dp[60][60];

int Y[] = {1, 1, 1, 0, -1, -1, -1, 0};
int X[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void initDP(){
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++)
                dp[i][j] = -1;
    }
}

int solve(int i, int j){
    //printf("%d %d\n",i, j);
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 1;
    for(int k=0; k<8; k++){
        if((i + X[k] >= 0 && j + Y[k] >= 0 ) && (i + X[k] < h && j + Y[k] <w ) )
            if(a[i+X[k]][j+Y[k]] == a[i][j] + 1)
                ans = max(ans, 1 + solve(i+X[k], j+Y[k]));
    }
    return dp[i][j] = ans;
}

int main(){
    int t=1;
    scanf("%d%d",&h,&w);
    while(h !=0 && w != 0){
        for(int i=0; i<h; i++){
            scanf("%s",str);
            for(int j=0; j<w; j++){
                a[i][j] = str[j] - 'A';
            }
        }
        int ans = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(a[i][j] == 0){
                    initDP();
                    //printf("NEW STATE\n");
                    ans = max(ans, solve(i, j));
                }
            }
        }
        printf("Case %d: %d\n",t, ans);
        scanf("%d %d",&h,&w);
        t++;
    }
    return 0;
}
