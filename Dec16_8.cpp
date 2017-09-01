#include<cstdio>
#include<cstring>
#include<cmath>

int V;
int N;

int graph[200][200];
int temp[200][200];
int sol[200][200];


void printSolution(int path[]);

bool isSafe(int v, int path[], int pos){
    if (graph [ path[pos-1] ][ v ] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamCycleUtil(int path[], int pos){
    if (pos == V+1){
        if ( graph[ path[pos-1] ][ path[1] ] == 1 )
           return true;
        else
          return false;
    }
    for (int v = 1; v <= V; v++){
        if (isSafe(v, path, pos)){
            path[pos] = v;
            if (hamCycleUtil (path, pos+1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamCycle(){
    int *path = new int[V+1];
    for (int i = 0; i <= V; i++)
        path[i] = -1;
    path[1] = 1;
    if ( hamCycleUtil(path, 2) == false ){
        printf("NO\n");
        return false;
    }
    printf("YES\n");
    printSolution(path);
    return true;
}

/*int Ceil(int n){
    long double v = (long double)(1.0 * n)/ (1.0 * N);
    if((long double) v - (int)n/N > 0.001 )
        return n/N + 1;
    return n/N;
}*/
void rel(int u, int v){
    int ui = ceil(1.0 * (1.0*u)/(1.0*N));
    int uj = u%N;
    if(uj == 0)
        uj = N;

    int vi = ceil(1.0 * (1.0*v)/(1.0*N));
    int vj = v%N;
    vj = vj == 0 ? N:vj;

    if(vi == ui){
        if(vj > uj)
            sol[ui][uj] = 'R';
        else
            sol[ui][uj] = 'L';
    } else{
        if(vi > ui)
            sol[ui][uj] = 'D';
        else
            sol[ui][uj] = 'U';
    }

   // printf("(%d %d) to (%d %d)\n",ui,uj,vi, vj);
}
void printSolution(int path[]){
    for(int i = 2; i <= V; i++){
        rel(path[i-1], path[i]);
    }
    rel(path[V], path[1]);
    //printf(" %d ", path[1]);
    for(int i=1; i<=N; i++){
        for(int j=1; j <= N; j++){
            printf("%c ",sol[i][j]);
        }
        printf("\n");
    }
}




//============================


void addEdge(int i, int j, int vi, int vj){
    graph[temp[i][j]][temp[vi][vj]] = 1;
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    char str[10];
    while(t--){
        for(int i=0; i<50; i++)
            for(int j=0; j<50; j++)
                graph[i][j] = 0;
        int n;
        scanf("%d",&n);

        int it=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                temp[i][j] = it;
                it++;
            }
        }
        V = temp[n][n];
        N = n;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                scanf("%s",str);
                for(int k=0; k<strlen(str); k++){
                    if(str[k] == 'U')
                        addEdge(i, j, i-1, j);
                    if(str[k] == 'D')
                        addEdge(i, j, i+1, j);
                    if(str[k] == 'L')
                        addEdge(i, j, i, j-1);
                    if(str[k] == 'R')
                        addEdge(i, j, i, j+1);
                }
            }
        }

        /*printf("graph:\n");
        for(int i=1; i<=n*n; i++){
            for(int j=1; j<=n*n; j++){
                printf("%d ",graph[i][j]);
            }
            printf("\n");
        }*/
        hamCycle();


    }
    return 0;

}
