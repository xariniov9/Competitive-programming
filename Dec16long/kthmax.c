// HIMANSHU TIWARI
// DECEMBER '16 LONG CHALLENGE
// XARINIOV9


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MOD 1000000007

typedef long long int LLI;

int Agli_Sankhya(){
	int num = 0;
    char c = getchar();
    while(!(c>='0' & c<='9'))
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

// MAIN PART STARTS HERE..

double
nthRoot(long long a, int n){
    if(n==2) return sqrt(a);
    if(n==3) return cbrt(a);
    return (double) pow(a, (double) 1.0 / (1.0*n));
}

int
safe(long long n, long long b){
    long long a = 1;
    while(a*b<=n) a = a*b;
    return a>(n-a);
}

int
lowerBound(int l, int u, long long n){
    while(l<=u){
        int m = (l+u)/2;
        int c1 = safe(n, m), c2 = safe(n, m-1);
        if(c1 && !c2)   return m;
        if(c1 && c2)    u = m-1;
        else            l = m+1;
    }
    return -1;
}

// MAIN PART STARTS HERE..

typedef struct {
    int v;    long long f;
} Count;

int arr[100003];
Count C[100003];
int lef[100003], rig[100003], stk[100003];
int Top;

void newStk(){
    Top = -1;
}
void push(int x){
    stk[++Top] = x;
}
int pop(){
    int x = stk[Top];
    Top--;
    return x;
}
int top(){
    return stk[Top];
}


int comparator(const void * a, const void * b){
    return ((Count * )b)->v - ((Count *)a)->v;
}

int BinSearch(int l, int u, long long key){
    while(l<=u){
        int m = (l+u)/2;
        if(C[m].f >= key && C[m-1].f < key){
            return m;
        } else if(C[m].f < key){
            l = m+1;
        } else u = m-1;
    }
    return -1;
}

void processing(int n){
    int i;
    arr[0] = arr[n+1] = 1e9+5;
    newStk(); push(0);
    for(i=1; i<=n; i++){
        while(arr[top()] < arr[i]) pop();
        lef[i] = top();   push(i);
    }
    newStk(); push(n+1);
    for(i=n; i>0; i--){
        while(arr[top()] <= arr[i]) pop();
        rig[i] = top();   push(i);
    }
    C[0].v = -1e9;    C[0].f = 0;
    for(i=1; i<=n; i++){
        C[i].v = arr[i];
        C[i].f = (long long)(rig[i]-i)*((long long)i-lef[i]);
    }
    qsort(C+1, n, sizeof(Count), comparator);
}

int main(){
    int n, m, i, t, T, Q;
    scanf("%d",&t);
	for(T=0; T<t; T++){
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        processing(n);
        for(i=1; i<=n; i++)
            C[i].f = C[i].f + C[i-1].f;
        for(Q=0; Q<m; Q++){
            long long q;
            scanf("%lld",&q);
            int x = BinSearch(1, n, q);
            printf("%d\n",C[x].v);
        }
	}
	return 0;
}
