#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iterator>
#include<vector>

#define MAX_N 100110
#define INF (1e9+2)

using namespace std;

typedef struct{
	int a;
	long long count;
} Pair;

long long a[MAX_N];
Pair pairr[MAX_N];
int stack[MAX_N];
int L[MAX_N];
int R[MAX_N];

void
stockspanLR(int n){
	int i, top=0;
	stack[0] = 0;
	for(i=1; i<=n; i++){
		while(a[stack[top]] < a[i])
			top--;
		L[i] = stack[top];
		stack[++top] = i;
	}
	top=0;
	stack[0]=n+1;
	for(i=n; i; i--){
		while(a[stack[top]] <= a[i])
			top--;
		R[i] = stack[top];
		stack[++top] = i;
	}
	pairr[0].a = -INF;
	pairr[0].count = 0;
	for(i=1; i<=n; i++){
		pairr[i].a = a[i];
		pairr[i].count = (long long)(((long long)R[i]-i)*((long long)i-L[i]));
	}
}

int
comp( const void * e1, const void * e2){
    	Pair *f = (Pair *) e1;
    	Pair *s = (Pair *) e2;
    	if(f->a > s->a)
    		return -1;
    	else if(f->a < s->a)
    		return 1;
    	else
    		return 0;
}

long long cnt[MAX_N] = {0};

int upb(int lb, int ub, long long p){
    while(lb <= ub){
        int mid = (lb+ub)/2;
        if(cnt[mid] >= p && cnt[mid-1] < p)
            return mid;
        else if(cnt[mid] < p)
            lb = mid+1;
        else
            ub = mid-1;
    }
    return -1;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m, i;
        scanf("%d%d",&n,&m);
        a[0] = a[n+1]= INF;
        for(i=1; i<=n; i++)
            scanf("%lld",a+i);
        stockspanLR(n);
       	qsort(pairr+1, n, sizeof(Pair), comp);
       	cnt[0] = 0;
       	for(int i=1; i<=n; i++){
            cnt[i] = (long long)cnt[i-1] + (long long)pairr[i].count;
       	}
       	cnt[n+1] = cnt[n] + 50;
       	for(int i=n+2; i<MAX_N; i++)
            cnt[i] = cnt[n-1];
        while(m--){
            long long curr =0;
            int i=1;
            long long p;
            scanf("%lld",&p);
            int x = upb(1, n, p);
            printf("%d\n",pairr[x].a);
        }
    }
    return 0;
}
