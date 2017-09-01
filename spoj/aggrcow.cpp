#include<bits/stdc++.h>

using namespace std;

int a[100005];
int n, c;

int ok(int d){
    int pl=1; long long lst=a[0];
    for(int i=0; i<n; i++){
        if(a[i] - lst >= d){
            pl++;
            lst = a[i];
            if(pl == c)
                return 1;
        }
    }
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        //int n, c;
        scanf("%d%d",&n,&c);
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        sort(a, a+n);
        int lb = 0, ub = a[n-1]-a[0]+1, ans, tmp;
        while(ub-lb > 1){
            int mid = (lb + ub)/2;
            (ok(mid) ? lb:ub) = mid;
        }
        printf("%d\n",lb);
    }
    return 0;
}
