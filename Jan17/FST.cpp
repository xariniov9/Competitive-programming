#include<bits/stdc++.h>


using namespace std;
#define s_size 10000110
int lpfact[s_size+5]={0};
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
	lpfact[1] = 1;
}


int chk(long long N){
    int cnt=0;
    while(N > 1){
        int v = lpfact[N];
        cnt=0;
        while(N%v == 0){
            N/=v;
            cnt++;
        }
        if(v%4 == 3 && cnt%2==1)
            return 0;
    }
    return 1;
}

long long fs[6];

long long int modular_pow(long long int base, int exponent){
    long long int result = 1;
    while (exponent > 0){
        if (exponent & 1)
            result = (result * base);
        exponent = exponent >> 1;
        base = (base * base);
    }
    return result;
}

long long Pow(long long a,  int n){
    return modular_pow(a, n);
}

long long tst = 0, tst1;
int fst(long long N, int it){
    if(it==-1) return N==0;
    if(N==1){
        fs[it] = 1;
        return 1;
    }
    if(N==0) return 1;

    if(it==0){
        long long x = sqrt(N);
        if((x*x) == N){
            fs[it] = x;
            return 1;
        }
        return 0;
    }

    int cnt = 0, flag=0;
    if(it==1){
        while(N%4 == 0){
            N/=4;
            cnt++;
        }
        if(N%2 == 0){
            flag=1;
            N/=2;
        }
        if(N<=10000000)
            if(!chk(N))
                return 0;
    }
    long long p = Pow(2, cnt);

    int ans = 0;
    long long x = sqrt(N);
    for(int i=x; i>=1; i--){
        fs[it] = i;
        ans = fst(N - (long long)i*i, it-1);
        //tst = max(tst, x-i);

        if(ans){
            if(tst < x-i){
            tst1 = N;
            tst = x-i;
            }
            if(it==1){
                if(flag){
                    long long A=fs[0], B=fs[1];
                    fs[0] = A+B;
                    fs[1] = abs(A-B);
                }
                fs[0] = p * fs[0];
                fs[1] = p * fs[1];
            }
            break;
        }
        else
            fs[it] = 0;
    }

    return ans;
}

void FST(long long T){
    int cnt = 0;
    fs[0]=fs[1]=fs[2]=fs[3] = 0;

    if(T==0)
        return;
    while(T%4 == 0){
        T/=4;
        cnt++;
    }

    int flag=0;
    if(T%2 == 0){
        flag=1;
        T/=2;
    }

    if(T%8 == 7){
        fs[3] = 1;
        fst(T-1, 2);
    }
    else
        fst(T, 2);

    if(flag){
        long long a=fs[0], b = fs[1], c=fs[2], d=fs[3];
        fs[0] = a+b;        fs[1] = abs(a-b);
        fs[2] = c+d;        fs[3] = abs(c-d);
    }
    long long  p = Pow(2, cnt);
    fs[0] = p * fs[0];    fs[1] = p * fs[1];    fs[2] = p * fs[2];    fs[3] = p * fs[3];
}


int main(){
    seive();
    long long t=9871464690;
    int x=1;
    while(x--){

        FST(t);
        printf("%lld %lld %lld %lld\n",fs[0],fs[1],fs[2],fs[3]);
        t++;
    }
    //printf("tst: %lld tst1 : %lld\n",tst,tst1);
    return 0;
}
