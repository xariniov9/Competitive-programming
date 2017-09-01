// HIMANSHU TIWARI
// DECEMBER '16 LONG CHALLENGE
// XARINIOV9

#include<cstdio>
#include<vector>
#include<cmath>

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


using namespace std;
vector<pair< pair<int, int>, pair<int, int> > > s;
void (*p[21]) ( int i, int j, bool r);
pair<pair<int, int>, pair<int, int> > mp(int ui, int uj, int vi, int vj, bool r){
    return make_pair(make_pair(ui, uj), make_pair(vi, vj));
	//return make_pair(make_pair(uj, ui), make_pair(vj, vi));
}
void f2(int i, int j, bool r){
    if(r)
	s.push_back(mp(i, j, i, j+1, r));
	else
      	s.push_back(mp(i, j, i+1, j, r));

}
void f4(int i, int j, bool r){
	f2(i, j, r);
	if(r){
        f2(i, j+2, r);
        s.push_back(mp(i, j+1, i, j+2, r));
        s.push_back(mp(i, j  , i, j+1, r));
        s.push_back(mp(i, j+1, i, j+2, r));
        s.push_back(mp(i, j  , i, j+1, r));
        s.push_back(mp(i, j+2, i, j+3, r));
	} else {
	    f2(i+2, j, r);
	    s.push_back(mp(i+1, j, i+2, j, r));
	    s.push_back(mp(i  , j, i+1, j, r));
        s.push_back(mp(i+1, j, i+2, j, r));
        s.push_back(mp(i  , j, i+1, j, r));
        s.push_back(mp(i+2, j, i+3, j, r));
	}
}
void f5(int i, int j, bool r){
	f4(i, j, r);
	if(r){
	s.push_back(mp(i, j+3, i, j+4, r));	s.push_back(mp(i, j+2, i, j+3, r));
    s.push_back(mp(i, j+1, i, j+2, r));    s.push_back(mp(i, j  , i, j+1, r));
    s.push_back(mp(i, j+1, i, j+2, r));    s.push_back(mp(i, j  , i, j+1, r));
    s.push_back(mp(i, j+2, i, j+3, r));	} else {
	s.push_back(mp(i+3, j, i+4, j, r));	s.push_back(mp(i+2, j, i+3, j, r));
    s.push_back(mp(i+1, j, i+2, j, r));    s.push_back(mp(i,   j, i+1, j, r));
    s.push_back(mp(i+1, j, i+2, j, r));    s.push_back(mp(i,   j, i+1, j, r));
    s.push_back(mp(i+2, j, i+3, j, r));

	}
}
void f8(int i, int j, bool r){
	f4(i, j, r);
	if(r){
        f4(i, j+4, r);
        s.push_back(mp(i, j+3, i, j+4, r));
        s.push_back(mp(i, j+2, i, j+3, r));
        s.push_back(mp(i, j+4, i, j+5, r));
        f4(i, j, r);
        f4(i, j+4, r);
	}else{
        f4(i+4, j, r);
        s.push_back(mp(i+3, j, i+4, j, r));
        s.push_back(mp(i+2, j, i+3, j, r));
        s.push_back(mp(i+4, j, i+5, j, r));
        f4(i, j, r);
        f4(i+4, j, r);
	}
}
void f5r(int i, int j, bool r){
    if(r){
	s.push_back(mp(i, j  , i, j+1, r));	s.push_back(mp(i, j+1, i, j+2, r));
    s.push_back(mp(i, j+2, i, j+3, r));    s.push_back(mp(i, j+3, i, j+4, r));
    s.push_back(mp(i, j+2, i, j+3, r));    s.push_back(mp(i, j+1, i, j+2, r));
    s.push_back(mp(i, j+3, i, j+4, r));    }else{
    s.push_back(mp(i,   j, i+1, j, r));	s.push_back(mp(i+1, j, i+2, j, r));
    s.push_back(mp(i+2, j, i+3, j, r));    s.push_back(mp(i+3, j, i+4, j, r));
    s.push_back(mp(i+2, j, i+3, j, r));    s.push_back(mp(i+1, j, i+2, j, r));
    s.push_back(mp(i+3, j, i+4, j, r));
    }
}
void f10(int i, int j, bool r){
	if(r)f4(i, j+6, r);
	else f4(i+6, j, r);
	f8(i, j, r);
	if(r){
	s.push_back(mp(i, j+7, i, j+8, r));	s.push_back(mp(i, j+8, i, j+9, r));
    s.push_back(mp(i, j+6, i, j+7, r));    s.push_back(mp(i, j+5, i, j+6, r));
    s.push_back(mp(i, j+4, i, j+5, r));    s.push_back(mp(i, j+6, i, j+7, r));
    s.push_back(mp(i, j+3, i, j+4, r));    s.push_back(mp(i, j+2, i, j+3, r));
    s.push_back(mp(i, j+1, i, j+2, r));    s.push_back(mp(i, j  , i, j+1, r));
    s.push_back(mp(i, j+1, i, j+2, r));    s.push_back(mp(i, j  , i, j+1, r));
    s.push_back(mp(i, j+2, i, j+3, r));	} else{
	s.push_back(mp(i+7, j, i+8, j, r));	s.push_back(mp(i+8, j, i+9, j, r));
    s.push_back(mp(i+6, j, i+7, j, r));    s.push_back(mp(i+5, j, i+6, j, r));
    s.push_back(mp(i+4, j, i+5, j, r));    s.push_back(mp(i+6, j, i+7, j, r));
    s.push_back(mp(i+3, j, i+4, j, r));    s.push_back(mp(i+2, j, i+3, j, r));
    s.push_back(mp(i+1, j, i+2, j, r));    s.push_back(mp(i,   j, i+1, j, r));
    s.push_back(mp(i+1, j, i+2, j, r));    s.push_back(mp(i,   j, i+1, j, r));
    s.push_back(mp(i+2, j, i+3, j, r));
    }
    if(r) f5r(i, j+5, r);
    else  f5r(i+5, j, r);
}
void f11(int i, int j, bool r){
	f10(i, j, r);
	if(r) f5(i, j+6, r);
	else  f5(i+6, j, r);
	if(r){
	s.push_back(mp(i, j+5, i, j+6, r));	s.push_back(mp(i, j+4, i, j+5, r));
    s.push_back(mp(i, j+5, i, j+6, r));    s.push_back(mp(i, j+4, i, j+5, r));
    s.push_back(mp(i, j+5, i, j+6, r));    s.push_back(mp(i, j+3, i, j+4, r));
    s.push_back(mp(i, j+2, i, j+3, r));    s.push_back(mp(i, j+1, i, j+2, r));
    s.push_back(mp(i, j  , i, j+1, r));    s.push_back(mp(i, j+1, i, j+2, r));
    s.push_back(mp(i, j  , i, j+1, r));    s.push_back(mp(i, j+2, i, j+3, r));
	} else{
	s.push_back(mp(i+5, j, i+6, j, r));	s.push_back(mp(i+4, j, i+5, j, r));
    s.push_back(mp(i+5, j, i+6, j, r));    s.push_back(mp(i+4, j, i+5, j, r));
    s.push_back(mp(i+5, j, i+6, j, r));    s.push_back(mp(i+3, j, i+4, j, r));
    s.push_back(mp(i+2, j, i+3, j, r));    s.push_back(mp(i+1, j, i+2, j, r));
    s.push_back(mp(i,   j, i+1, j, r));    s.push_back(mp(i+1, j, i+2, j, r));
    s.push_back(mp(i,   j, i+1, j, r));    s.push_back(mp(i+2, j, i+3, j, r));
	}
}
void f13(int i, int j, bool r){
	if(r) f4(i, j+9, r);
	else f4(i+9, j, r);
	f11(i, j, r);
	if(r){
	s.push_back(mp(i, j+10, i, j+11, r));	s.push_back(mp(i, j+11, i, j+12, r));
    s.push_back(mp(i, j+10, i, j+11, r));    s.push_back(mp(i, j+11, i, j+12, r));
    }else{
    s.push_back(mp(i+10, j, i+11, j, r));	s.push_back(mp(i+11, j, i+12, j, r));
    s.push_back(mp(i+10, j, i+11, j, r));    s.push_back(mp(i+11, j, i+12, j, r));
    }
    f11(i, j, r);
}
void f16(int i, int j, bool r){
	if(r) f4(i, j+12, r);
	else f4(i+12, j, r);
	f13(i, j, r);
	if(r){
	s.push_back(mp(i, j+12, i, j+13, r));	s.push_back(mp(i, j+13, i, j+14, r));
    s.push_back(mp(i, j+12, i, j+13, r));
    }else{
    s.push_back(mp(i+12, j, i+13, j, r));	s.push_back(mp(i+13, j, i+14, j, r));
    s.push_back(mp(i+12, j, i+13, j, r));
    }
    if(r)f5(i, j+11, r);
    else f5(i+11, j, r);
}
void f20(int i, int j, bool r){
	if(r) f11(i, j+9, r);
	else f11(i+9, j, r);
	f11(i, j, r);
	if(r){
	s.push_back(mp(i, j+10, i, j+11, r));	s.push_back(mp(i, j+11, i, j+12, r));
    s.push_back(mp(i, j+12, i, j+13, r));    s.push_back(mp(i, j+11, i, j+12, r));
    s.push_back(mp(i, j+10, i, j+11, r));    s.push_back(mp(i, j+12, i, j+13, r));
    }else{
    s.push_back(mp(i+10, j, i+11, j, r));	s.push_back(mp(i+11, j, i+12, j, r));
    s.push_back(mp(i+12, j, i+13, j, r));    s.push_back(mp(i+11, j, i+12, j, r));
    s.push_back(mp(i+10, j, i+11, j, r));    s.push_back(mp(i+12, j, i+13, j, r));
    }
    if(r) f16(i, j+1, r);
    else f16(i+1, j, r);
    if(r) f16(i, j+4, r);
    else f16(i+4, j, r);
}
void solve(int n){
	for(int i=1; i<=n; i++)
		(*p[n])(i, 1, true);
	for(int j=1; j<=n; j++)
		(*p[n])(1, j, false);
	printf("%d\n",s.size());
	for(int i=0; i<s.size(); i++){
		printf("%d %d %d %d\n",s[i].first.first, s[i].first.second, s[i].second.first, s[i].second.second);
	}
	s.clear();
}
int main(){
	p[2] = f2;	p[4] = f4;	p[5] = f5;	p[8] = f8;
	p[11] =f11;	p[13] =f13;	p[16] =f16;	p[20] =f20;
	//int t;	scanf("%d",&t);
	//while(t--){
		int n;
		scanf("%d",&n);
		solve(n);
	//}
	return 0;
}

/*

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
int lef[100003];
int rig[100003];
int stk[100003];
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
        lef[i] = top();
        push(i);
    }
    newStk(); push(n+1);
    for(i=n; i>0; i--){
        while(arr[top()] <= arr[i]) pop();
        rig[i] = top();
        push(i);
    }
    C[0].v = -1e9;
    C[0].f = 0;
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


*/
