// HIMANSHU TIWARI
// DECEMBER '16 LONG CHALLENGE
// XARINIOV9

#include<stdio.h>

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

int main(){
    int t, val [] = {0, 4, 5, 6, 1, 2, 3, 8, 7};
    int T= Agli_Sankhya();
    for(t=0; t<T; t++){
        int n;// = Agli_Sankhya();
        scanf("%d",&n);
        int col_no = n%8;
        col_no = col_no == 0 ? 8 : col_no;
        int res = n + (val[col_no] - col_no);
        printf("%d",res);
        if(col_no == 3 || col_no ==6)   printf("UB\n");
        if(col_no == 2 || col_no ==5)   printf("MB\n");
        if(col_no == 1 || col_no ==4)   printf("LB\n");
        if(col_no == 7)                 printf("SU\n");
        if(col_no == 8)                 printf("SL\n");
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
