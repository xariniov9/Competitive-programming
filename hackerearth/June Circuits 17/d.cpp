#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int a[100005];
int b[100005];
int dp1[100005];
int sum[100005];
int stk[100005];

int pre(int n){
    int top = 0;
    stk[top] = n;
    for(int i=n-1; i>=0; i--){
        while(a[stk[top]] <= a[i])
            top--;
        b[i] = stk[top];
        stk[++top] = i;
    }
    /*printf("B : ");
    for(int i=0; i<n; i++)
        printf("%d ",b[i]);
    printf("\n");*/
    dp1[n] = 0;
    sum[n] = 0;
    for(int i=n-1; i>=0; i--){
        if(b[i] == n){
            dp1[i] = sum[i+1] + 1;
            if(dp1[i] >= MOD)
                dp1[i] -= MOD;
        } else{
            dp1[i] = dp1[i+1];
        }
        sum[i] = sum[i+1] + dp1[i];
        if(sum[i] >= MOD)
            sum[i] -= MOD;
    }
    return dp1[0];
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        a[n] = 10000004;
        printf("%d\n",pre(n));
    }
    return 0;

}
