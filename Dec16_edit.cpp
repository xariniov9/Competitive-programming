#include<cstdio>
#include<cstring>

using namespace std;
char s[200005], t[200005];

int arr[30][30];

/*

#include<cstdio>
#include<cmath>

using namespace std;




int canBe(long long n, long long base){
    long long tmp = 1;
    while(tmp * base <= n){
        tmp = tmp * base;
    }
    if(tmp > n - tmp)
        return 1;
    return 0;
}
double nrt(long long a, int n){
    return (double) pow(a, (double)1.0/(1.0*n));
}

int bsrch(int lb, int ub, long long n){
    int c1, c2;
    while(lb<=ub){
        int mid = (lb+ub)/2;

        if(((c1 = canBe(n, mid))==1) && ( (c2 = canBe(n, mid-1) ) == 0))
            return mid;
        else if((c1==1) && (c2==1))
            ub = mid-1;
        else
            lb = mid+1;
    }
    return -1;
}
long long solve(long long n){
    long long ret = 0;

    double crt = cbrt(n);
    double srt = sqrt(n);

    if(canBe(n, srt)){
        int lb = bsrch(ceil(crt), srt, n);
        if(lb == 2)
            lb++;
        if(lb == -1)
            lb = srt;
        ret +=  (long long)srt - lb + 1;
    }
    /*for(int i=sqrt(n); i>=ceil(crt) && i>2; i--){
        if(canBe(n, i)){
            ret++;
        }else{
            break;
        }
    }
    double froot = nrt(n, 4);

    if(canBe(n, crt)){
        int lb = bsrch(ceil(froot), crt, n);
        if(lb == 2)
            lb++;
        if(lb == -1)
            lb = crt;
        ret +=  (long long)crt - lb + 1;
    }
    /*for(int i=floor(crt); i>=ceil(froot) && i>2; i--){
        if(canBe(n, i)){
            ret++;
        }else{
            break;
        }
    }

    double fifroot = nrt(n, 5);
    if(canBe(n, froot)){
        int lb = bsrch(ceil(fifroot), froot, n);
        if(lb == 2)
            lb++;
        if(lb == -1)
            lb = froot;
        ret +=  (long long)froot - lb + 1;
    }
    /*for(int i = floor(froot); i>=ceil(fifroot) && i>2; i--){
        if(canBe(n, i)){
            ret++;
        }else{
            break;
        }
    }

    for(int i=3; i<=floor(fifroot); i++){
        ret += canBe(n, i);
    }
    return ret + 1 + ceil(1.0 * (1.0*n)/(2.0));
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long ans, n;
        scanf("%lld",&n);
        if(n==1){
            printf("INFINITY\n");
            continue;
        }
        if(n==2)
            printf("1\n");
        else if(n==3){
            printf("2\n");
        } else if(n==4)
            printf("3\n");
        else{
            ans = solve(n);
            printf("%lld\n",ans);
        }
    }
    return 0;
}


*/
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s\n",s);
        scanf("%s\n",t);

        int I, D, W;
        scanf("%d %d %d\n",&I, &D, &W);

        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                scanf("%d",&arr[i][j]);
            }
        }
        int slen = strlen(s);
        int tlen = strlen(t);

        printf("%d\n",max(slen,  tlen));

        if(slen >= tlen){
            for(int i=0; i<tlen; i++){
                printf("R %d %c\n",i+1, t[i]);
            }
            for(int i=tlen; i<slen; i++){
                printf("D %d\n",slen+1);
            }
        } else {
            for(int i=0; i<slen; i++){
                printf("R %d %c\n",i+1,t[i]);
            }
            for(int i=slen; i<tlen; i++){
                printf("I %d %c\n",i, t[i]);
            }
        }
        /*char pos[30] = {0};
        for(int i=0; i<slen; i++){
            pos[s[i] - 'A'] = i+1;
        }

        int Q = 0;
        for(int i = 0; i<26; i++){
            if(pos[i]){
                Q++;
            }

        }
        printf("%d\n",Q+tlen);

        for(int i=0; i<26; i++){
            if(pos[i]){
                printf("D %d\n",pos[i]);
            }
        }*/
        /*for(int i=0; i<slen; i++){
            printf("D 1\n");
        }

        for(int i=0; i<tlen; i++){
            printf("I %d ",i);
            printf("%c",t[i]);
            printf("\n");
        }*/

        fflush(stdout);
    }
    return 0;
}
