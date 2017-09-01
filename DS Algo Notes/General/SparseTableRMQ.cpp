// https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/

#include<bits/stdc++.h>

using namespace std;

int a[100001];
int M[100001][20];

void preprocess(int N){
    int i, j;
    //initialize for intervals of length 1
    for(i=0; i<N; i++)
        M[i][0] = i;
    //compute from smaller to larger..
    for(j=1; (1<<j) <= N; j++){
        for(i=0; i+(1<<j)-1 < N; i++){
            if(a[M[i][j-1]] < a[M[i+(1<<(j-1))][j-1]])
                M[i][j] = M[i][j-1];
            else
                M[i][j] = M[i+(1<<(j-1))][j-1];
        }
    }
}

int RMQ(int l, int r){
    int k = log(r-l+1);
    if(a[M[l][k]] <= a[M[r-(1<<k) + 1][k]])
        return M[l][k];
    else
        return M[r-(1<<k) + 1][k];
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    preprocess(n);
    int q;
    scanf("%d",&q);
    while(q--){
        int l, r;
        // 0-indexed
        scanf("%d%d",&l,&r);
        printf("%d\n",RMQ(l, r));   //returns index!
    }
    return 0;
}
