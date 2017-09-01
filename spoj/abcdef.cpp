#include<bits/stdc++.h>

using namespace std;

int a[105];
vector<int> v1, v2;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    //cal v1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                v1.push_back(a[i] * a[j] + a[k]);
            }
        }
    }
    sort(v1.begin(), v1.end());
    //cal v2;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(a[k] == 0)
                    continue;
                v2.push_back((a[i] + a[j])*a[k]);
            }
        }
    }
    sort(v2.begin(), v2.end());
    long long ans = 0;
    for(int i=0; i<v1.size(); i++){
        ans += upper_bound(v2.begin(), v2.end(), v1[i]) - lower_bound(v2.begin(), v2.end(), v1[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
