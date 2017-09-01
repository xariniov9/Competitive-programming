#include<bits/stdc++.h>

using namespace std;

int a[10005], b[10005];

int main(){
    int n, m;
    scanf("%d",&n);
    while(n){
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int i=0; i<m; i++)
            scanf("%d",&b[i]);

        int ans =0;
        int i=0, j=0, it=0, s1=0, s2=0;
        while(i<n && j<m){
            if(a[i] == b[j]){
                ans += a[i] + max(s1, s2);
                i++; j++;
                s1=s2=0;
               // printf("ANS : %d\n",ans);
            } else if(a[i] > b[j]){
                s2 += b[j];
                j++;
            } else{
                s1 += a[i];
                i++;
            }
            //printf("(%d %d) ",s1, s2);
        }
        //printf("\n");
        while(i<n){
            s1 += a[i++];
        }
        while(j<m){
            s2 += b[j++];
        }
        printf("%d\n",ans + max(s1, s2));

        scanf("%d",&n);
    }

}
