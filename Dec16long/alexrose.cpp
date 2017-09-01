// HIMANSHU TIWARI
// DECEMBER '16 LONG CHALLENGE
// XARINIOV9


/*

*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>

using namespace std;

#define MOD 1000000007

typedef long long int LLI;

int Agli_Sankhya(){
	int num = 0;
    char c = getchar();
    while(!((c>='0') & (c<='9')))
        c=getchar();
    while(c>='0' && c<='9'){
        num = (num<<1)+(num<<3)+c-'0';
        c=getchar();
    }
	return num;
}

int adhiktam( int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

int nyoontam(int a, int b){
	if(a < b)
		return a;
	else
		return b;
}

inline int
addMod( int a, int b){
	LLI v=a;
	v+=b;
	if(v>=MOD) v-=MOD;
	return (int)v;
}

inline int
mulMod( int a, int b){
	LLI v=a;
	v*=b;
	if(v>MOD) v = v%MOD;
	return (int)v;
}

inline int
subMod( int a, int b){
	int v = a-b;
	if(v<0)	v+=MOD;
	return v;
}
vector<int> v(1000000);



//ref : http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
int upb(vector<int> &t, int l, int r, int key){
    while(r-l >1){
        int mid = l + (r-l)/2;
        if(t[mid] >= key) r=mid;
        else l=mid;
    }
    return r;
}

int lis(int lb, int ub){
    if(lb==ub) return 1;
    vector<int> t(ub-lb+1, 0);
    int l=1;    t[0] = v[0];
    for(int i=lb+1; i<=ub; i++){
        if(v[i] < t[0]) t[0] = v[i];
        else if(v[i] > t[l-1])  t[l++] = v[i];
        else t[upb(t, -1, l-1, v[i])] = v[i];
    }
    return l;
}


long long int a[112345];

int comp(const void * a, const void * b){
    if(*(int *) a > *(int *)b)
        return 1;
    else if(*(int*)a < *(int *) b)
        return -1;
    return 0;
}

int main(){
    int i, t, T; //val [] = {0, 4, 5, 6, 1, 2, 3, 8, 7};
    //int T= Agli_Sankhya();
    scanf("%d",&T);
    for(t=0; t<T; t++){
       int n, k;
       scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++)
            scanf("%lld",&a[i]);
        qsort(a, n, sizeof(long long), comp);
        // coordinate compression..
        a[n] = -1;
        long long prev = a[0], itr = 1;
        a[0] = 1;
        for(int i=1; i<n; i++){
            if(a[i] == prev){
                a[i] = a[i-1];
            } else{
                prev = a[i];
                a[i] = ++itr;
            }
        }
        multiset<long long> Set;
        int mxfreq = 0;
        for(int i=n-1; i>n-k-1; i--){
            mxfreq = a[i] == a[i+1] ? mxfreq+1 : 1;
        }
        Set.insert(mxfreq);
        int nxtSeq;
        if(mxfreq == k){
            mxfreq=0;
            nxtSeq=0;
        }else
            nxtSeq=a[n-k];

        for(int i=n-k-1; i>=0; i--){
            mxfreq = a[i] == a[i+1] ? mxfreq+1:1;
            if((i%k) == 0){
                Set.insert(mxfreq);
                nxtSeq = a[i];
                mxfreq=mxfreq == k ? 0 : mxfreq;
                if(mxfreq == 0){
                    nxtSeq = 0;
                }
            } else{
                if(nxtSeq == a[i]){
                    multiset<long long>::iterator it = Set.lower_bound(mxfreq-1);
                    Set.erase(it);
                    Set.insert(mxfreq);
                    if(mxfreq==k){
                        mxfreq= nxtSeq = 0;
                    }
                    continue;
                }
                if((a[i] != a[i-1] || mxfreq ==k) && *(Set.begin()) < mxfreq){
                    Set.erase(Set.begin());
                    Set.insert(mxfreq);
                }
                mxfreq=mxfreq == k ? 0 : mxfreq;
            }
        }
        int ans = 0;
        for(auto currentBucket : Set)
            ans += (k-currentBucket);
        printf("%d\n",ans);
    }
    return 0;
}


/*
int main(){
	int T, t, n, i, j;
    pre();
	scanf("%d",&t);
	for(T=0; T<t; T++){
		scanf("%d",&n);
		for(i=1; i<=n; i++)
			scanf("%d",&arr[i]);
		for(i =1; i<=n; i++){
			int x=1;
			while(arr[i]>1){
				x = x*lop[arr[i]];
				int prev = lop[arr[i]];
				while(arr[i] > 1 && lop[arr[i]] == prev)
					arr[i] /= lop[arr[i]];
			}
			arr[i] = x;
		}
		if(TEST){
			printf("After Preprocess: ");
			for(i=1; i<=n; i++)
				printf("%d ",arr[i]);
			printf("\n");
		}
		DP[1]=0;
		for(i=1; i<=n+1; i++)
			DP[i] = 1;
        int currFactor, ans=0;
		for(i=1; i<=n; i++){
			if(arr[i] > 1) DP[i] = 1 + DP[hash[arr[i]]];
            currFactor = arr[i];
            while(currFactor>1){
                DP[i] = adhiktam(DP[i], 1+DP[hash[lop[currFactor]]]);
                hash[lop[currFactor]] = i;
                currFactor/=lop[currFactor];
            }
            ans = adhiktam(ans, DP[i]);
            hash[arr[i]] = i;
		}
		for(i=1; i<=n; i++){
            hash[arr[i]]=0;
            while(arr[i] > 1){
                hash[lop[arr[i]]] = 0;
                arr[i] /= lop[arr[i]];
            }
		}
		printf("%d\n",ans);
	}
	return 0;
}



*/

