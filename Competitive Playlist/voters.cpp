#include<bits/stdc++.h>
using namespace std;
int a[3*50010], d[3*50010];

int main(){
    int n1, n2, n3, it=0;
    cin>>n1>>n2>>n3;
    for(int i=0; i<n1 + n2 + n3; i++)
        cin>>a[i];
    sort(a, a+(n1+n2+n3));
    int i=0;
    while(i<n1+n2+n3){
        int ele = a[i];
        int cnt = 0;
        while(a[i] == ele){
            cnt++;
            i++;
        }
        if(cnt>1)
            d[it++] = ele;
    }
    cout<<it<<endl;
    for(int i=0; i<it; i++)
        cout<<d[i]<<endl;
    return 0;
}
