
#include<bits/stdc++.h>

using namespace std;
int main(){
    int n, mx=-1, wn;
    int F=0, S=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int f, s;
        scanf("%d%d",&f, &s);
        F += (f-s);
        S += (s-f);
        if(mx < max(F, S)){
            mx = max(F, S);
            wn = F>S ? 1 : 2;
        }
    }
    printf("%d %d",wn, mx);
    return 0;
}
