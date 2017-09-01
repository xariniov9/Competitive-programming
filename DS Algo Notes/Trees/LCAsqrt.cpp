// divide into sqrt(H) sections!


/*
    P[] : PREPROCESSED ARRAY FOR ALL NODES
    T[] : T[i] REPRESENTS PARENT OF ith NODE
    L[] : LEVEL OF NODE i
    nr : [SQRT(H)]

    TREE IS ROOTED AT NODE 1
*/

//if node is situated in the first
//section then P[node] = 1
//if node is situated at the beginning
//of some section then P[node] = T[node]
//if none of those two cases occurs, then
//P[node] = P[T[node]]

#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > tree(100000);

int maxHeight = 0;
int P[100000];
int T[100000];
int L[100000];

void initDFS(int node, int parent, int level){
    L[node] = level;
    T[node] = parent;
    maxHeight = max(maxHeight, level);
    for(int i=0; i<tree[node].size(); i++){
        if(tree[node][i] != parent)
            initDFS(tree[node][i], node, level+1);
    }
}


// PREPROCESSING !
void dfs(int node, int N, int nr){
    int k;
    if(L[node] < nr){
        P[node] = 1;       //root for first section
    } else{
        if(!(L[node] % nr))
            P[node] = T[node];
        else
            P[node] = P[T[node]];
    }
    for(int i=0; i<tree[node].size(); i++){
        if(T[node] != tree[node][i])
            dfs(tree[node][i], N, nr);
    }
}

int LCA(int x, int y){
    while(P[x] != P[y]){
        if(L[x] > L[y])
            x = P[x];
        else
            y = P[y];
    }
    // now they are in same section!
    while(x != y){
        if(L[x] > L[y])
            x = T[x];
        else
            y = T[y];
    }
    return x;
}

int main(){

    int u, v, n;
    scanf("%d",&n);
    for(int i=0; i<n-1; i++){
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    initDFS(1, 1, 0);
    int nr = sqrt(maxHeight);
    dfs(1, n, nr);
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&u,&v);
        printf("LCA(%d, %d) : %d\n", u, v, LCA(u, v));
    }
    return 0;
}


/*
13
1 2
1 3
1 4
3 5
3 6
3 7
6 8
6 9
7 10
7 11
10 12
10 13

*/
