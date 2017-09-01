
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;



#define s_size 10000000
int lpfact[10000001]={0};

void
seive(){
	long long i, j;
	for(i=2; i<=s_size; i+=2)
		lpfact[i]=2;
	for(i=3; i<s_size; i+=2){
		if(!lpfact[i]){
			lpfact[i]=i;
			for(j=i; (j*i)<s_size; j+=2){
				if(!lpfact[j*i])
					lpfact[j*i]=i;
			}
		}
	}
}


int a[100005];


void pre(int n){
    int val;
    for(int i=1; i<=n; i++){
        val = a[i];
        a[i] = 1;
        if(val == 1)
            continue;
        while(val!=1){
            int currlp = lpfact[val];
            a[i] = a[i] * currlp;
            while(val != 1 && currlp == lpfact[val]){
                val = val/lpfact[val];
            }
        }
    }
}

int dp1[100005];
int hm[10000001] = {0};

int solveFinal(int n){

    dp1[0] = 0;

    for(int i=1; i<=n; i++){
        if(a[i] != 1){
            dp1[i] = 1 + dp1[hm[a[i]] ];
        }
        int val = a[i];
        while(val != 1){
            dp1[i] = max(dp1[i], 1 + dp1[hm[lpfact[val]]]);

            hm[lpfact[val]] = i;
            val = val/lpfact[val];
        }
        if(a[i]!=1)
            hm[a[i]] = i;
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, dp1[i]);
    }

    for(int i=1; i<=n; i++){
        int val = a[i];
        hm[a[i]] = 0;
        while(val != 1){
            hm[lpfact[val]] = 0;
            val = val/lpfact[val];
        }
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    seive();
    while(t--){
        int n, i, j;
        scanf("%d",&n);
        for(i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }
        pre(n);

        dp1[0] = 0;
        for(i =1; i<n+2; i++){
            dp1[i] = 1;
        }

        int ans = solveFinal(n);

        printf("%d\n", ans);
    }
    return 0;
}
