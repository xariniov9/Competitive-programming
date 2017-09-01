// HIMANSHU TIWARI
// DECEMBER '16 LONG CHALLENGE
// XARINIOV9

#include<stdio.h>
#include<stdlib.h>

#define MOD 1000000007
#define TEST 0

typedef long long int LLI;

int lop[10000001] = {0};
int arr[112345] = {0};
int DP[112345] = {0};
int hash[10000001] = {0};

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

/*
int Agli_Sankhya(){
	int num = 0;
    char c = getchar_unlocked();
    while(!(c>='0' & c<='9'))
        c=getchar_unlocked();
    while(c>='0' && c<='9'){
        num = (num<<1)+(num<<3)+c-'0';
        c=getchar_unlocked();
    }
	return num;
}*/

void pre(){
	long long i, j;
	for(i=2; i<=1e7+1; i+=2){
		lop[i] = 2;
	}
	for(i=3; i<=1e7+1; i+=2){
		if(!lop[i]){
			lop[i] = i;
			j=i;
			while(j*i < 1e7+1){
				if(!lop[j*i])
					lop[j*i] = i;
				j+=2;
			}
		}
	}
	lop[1] =1;
}


/*

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

*/
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
