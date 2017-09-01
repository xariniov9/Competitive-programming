#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>

#define inf 1e7

using namespace std;

int freq[112345];
long long a[112345];
int dp[2120][2120];

int n, k, tb;

int solver(int idx, int surplus){
    if(idx == -1){
        if(surplus == 0) return 0;
        return inf;
    }
    if(surplus<0 || tb > idx+1)
        return inf;

    if(dp[idx][surplus] != -1)
        return dp[idx][surplus];
    int ans = inf;
    if(surplus >= k - freq[idx] && k-freq[idx] <= freq[idx] && tb > 0){
        tb--;
        ans = solver(idx-1, surplus - (k-freq[idx]));
        tb++;
        return (dp[idx][surplus] = ans);
    }
    if(surplus >= k - freq[idx] && tb > 0){
        tb--;
        ans = solver(idx-1, surplus - (k-freq[idx]));
        tb++;
    }
    return (dp[idx][surplus] = ans);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        vector<long long> vec;
        int cnt = 0;
        scanf("%d%d",&n,&k);
        cnt = n;
        tb = n/k;
        for(int i=0; i<=n+1; i++)
            freq[i] = 0;
        int x;
        for(int i=0; i<n; i++){
            scanf("%lld",&a[i]);
            vec.push_back(a[i]);
        }
        if(k==1){
            printf("0\n");
            continue;
        }
  		sort(vec.begin(), vec.end());
		vector<long long>::iterator it=unique(vec.begin(), vec.end());
   		vec.resize(distance(vec.begin(), it) );

        for(int i = 0; i<n; i++){
			a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
			freq[a[i]]++;
		}
        n = vec.size();

        int numBuck = 0;
        for(int i=0; i<n; i++){
            numBuck += freq[i]/k;
            freq[i] = freq[i] % k;
        }
        tb -= numBuck;


        for(int i=0; i<=n+2; i++)
            for(int K=0; K<=cnt+1; K++)
                dp[i][K] = -1;

        int ans = solver(n-1, 0);

        printf("%d\n", ans);
    }
    return 0;
}
