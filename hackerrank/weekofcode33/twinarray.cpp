#include<bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first;
}

vector<pair<int, int> >a, b;

int main(){
    int n, x;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&x);
        a.push_back(make_pair(x, i));
    }
    sort(a.begin(), a.end(), cmp);
    for(int i=0; i<n; i++){
        scanf("%d",&x);
        b.push_back(make_pair(x, i));
    }
    sort(b.begin(), b.end(), cmp);

    int i=0, j=0;
    int ans;
    if(a[i].second == b[j].second){
        if(a[i+1].first < b[j+1].first){
            i++;
        } else
            j++;
    }
    printf("%d\n",a[i].first + b[j].first);
    return 0;
}
