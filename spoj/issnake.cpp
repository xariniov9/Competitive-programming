#include<bits/stdc++.h>

using namespace std;

int vis[2][505] = {0};
char str[505];
int n;

bool dfs(int x, int y, int count){
    if(y<n && vis[(x+1) %2][y] ==1 && vis[x][y+1]==1)
        return count==0 ? 1:0;

    if(vis[x][y])
        return 0;

    count--;
    if(count == 0)
        return 1;
    vis[x][y] = 1;

    bool ans = dfs((x+1)%2, y, count) || dfs(x, y+1, count);

    vis[x][y] = 0;
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int count = 0;
        scanf("%d",&n);

        scanf("%s",str);
        for(int i=0; i<n; i++)
            if(str[i] =='.')
                vis[0][i] = 1;
            else
                count++;
        scanf("%s",str);
        for(int i=0; i<n; i++)
            if(str[i] =='.')
                vis[1][i] = 1;
            else
                count++;

        int f =0;
        for(;f<n;f++)
            if(vis[0][f] == 0)
                break;
        bool ans = dfs(0, f, count);

        f =0;
        for(;f<n;f++)
            if(vis[1][f] == 0)
                break;

        memset(vis, 0, sizeof vis);
        ans = ans || dfs(1, f, count);
        if(ans)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
