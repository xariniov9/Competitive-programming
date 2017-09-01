#include<bits/stdc++.h>

using namespace std;

int a[1000005];
int ans[1000005];

int main(){
    int n, k;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);

    deque<int> qi;
    int it=0;
    for(int i=0; i<k; i++){
        while(!qi.empty() && a[i] > a[qi.back()])
            qi.pop_back();
        qi.push_back(i);
    }
    ans[it++] = a[qi.front()];

    for(int i=k; i<n; i++){
        if(!qi.empty() && i - qi.front() + 1 > k)
            qi.pop_front();
        while(!qi.empty() && a[i] > a[qi.back()])
            qi.pop_back();
        qi.push_back(i);
        ans[it++] = a[qi.front()];
    }

    for(int i=0; i<it; i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
