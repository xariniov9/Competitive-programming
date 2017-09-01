#include<bits/stdc++.h>

using namespace std;

int a[20005];
int st[4*20005];

int mxNum;
int initNum(){
    for(int i=0; i<31; i++)
        mxNum |= (1<<i);
}

void buildTree(int idx, int lb, int ub){
    if(lb == ub){
        st[idx] = a[lb];
        return;
    }
    buildTree(2*idx, lb, (lb+ub)/2);
    buildTree(2*idx+1, (lb + ub)/2 + 1, ub);

    st[idx] = st[2*idx] & st[2*idx+1];
}

int query(int idx, int lb, int ub, int x, int y){
    if(x > ub || y<lb || lb>ub)
        return mxNum;
    if(lb>=x && ub<=y)
        return st[idx];
    return query(2*idx, lb, (lb+ub)/2, x, y) & query(2*idx+1, (lb+ub)/2+1, ub, x, y);
}

int main(){

    int t;
    scanf("%d",&t);
    initNum();
//    printf("mxNum : %d\n",mxNum);
    while(t--){
        int n, k;
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        buildTree(1, 0, n-1);
  /*      printf("stree:\n");
        for(int i=1; i<4*n; i++){
            printf("%d ",st[i]);
        }
        printf("\n");*/
        k = min(k, n);
        for(int i=0; i<n; i++){
            int x = i-k;
            int y = i+k;

            if(x<0)  x = 0;
            if(y>=n) y= n-1;
            printf("%d ",query(1, 0, n-1, x, y));
        }
        printf("\n");
    }
    return 0;
}
