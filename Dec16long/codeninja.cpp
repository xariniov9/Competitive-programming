#include<cstdio>
#include<cmath>

using namespace std;

int lop[100005] = {0};
int prime[100005];
int it = 0;

void pre(){
	long long i, j;
	for(i=2; i<=100000; i+=2){
		lop[i] = 2;
	}
	prime[0] = 2;
	for(i=3; i<=100000; i+=2){
		if(!lop[i]){
			lop[i] = i;
			prime[it++] = i;
			j=i;
			while(j*i < 100001){
				if(!lop[j*i])
					lop[j*i] = i;
				j+=2;
			}
		}
	}
}

int a[200004];

int numP(int n){

    if(n<=1)
        return 0;
    int ret = 0;
    while( ){
        if()


    }


}
int main(){
    int n, q;
    scanf("%d%d",&n,&q);
    pre();
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        a[i] = numP(a[i]);
    }
    while(q--){
        scanf("%d%d%d",&l, &r, &k);
        printf("%d\n",solve(l, r, k));
    }
    return 0;
}
