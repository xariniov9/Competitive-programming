#include<bits/stdc++.h>

using namespace std;
int n, m;
int vis[184][184];
int a[184][184];
char str[190];

queue<pair<int, int> > Q;

int X[] = {0, -1, 0, 1};
int Y[] = {-1, 0, 1, 0};

void bfs(){
    while(!Q.empty()){
        pair<int, int> front = Q.front();
        Q.pop();
        for(int i=0; i<4; i++){
            int newx = front.first + X[i];
            int newy = front.second + Y[i];

            if(newx<0 || newy<0 || newx >= n || newy >=m)
                continue;
            if(a[front.first][front.second] + 1 < a[newx][newy]){
                a[newx][newy] = a[front.first][front.second] + 1;
                Q.push(make_pair(newx, newy));  //act as visited!
            }
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        //int n, m;
        scanf("%d%d",&n,&m);
        memset(vis, 0, sizeof vis);

        for(int i=0; i<n; i++){
            scanf("%s",str);
            for(int j=0; j<m; j++){
                if(str[j]-'0'){
                    a[i][j] = 0;
                    Q.push(make_pair(i, j));
                }else
                    a[i][j] = 100000;
            }
        }
        bfs();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        while(!Q.empty())
            Q.pop();
    }
    return 0;
}
