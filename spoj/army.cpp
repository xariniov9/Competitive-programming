#include<bits/stdc++.h>

using namespace std;

int a[1000005], b[1000005];

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int n, m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<m; i++)
            scanf("%d",&b[i]);

        sort(a, a+n);
        sort(b, b+m);

        int i=0, j=0;

        while(i<n && j<m){
            if(b[j] <= a[i])
                j++;
            else i++;
        }
        if(i==n)
            printf("MechaGodzilla\n");
        else
            printf("Godzilla\n");
    }
    return 0;
}
