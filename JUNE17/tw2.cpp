#include<bits/stdc++.h>

using namespace std;

int a[1000005];

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, k;
        scanf("%d%d",&n,&k);
        vector<pair<int, int> > v;
        vector<int> arr;
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
            v.push_back(make_pair(a[i], i));
        }
        sort(v.begin(), v.end(), cmp);

        for(int i=0; i<n; i++){
            if(k > 0 && k >= v[i].second - i){
                k -= max(0, v[i].second - i);
                arr.push_back(v[i].first);
                a[v[i].second] *= -1;
            }
        }
        for(int i=0; i<arr.size(); i++)
            printf("%d ",arr[i]);
        for(int i=0; i<n; i++){
            if(a[i] >= 0)
                printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
