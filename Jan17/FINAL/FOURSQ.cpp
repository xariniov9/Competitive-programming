

// HIMANSHU TIWARI
// XARINIOV9


// JAN'17 LONG CHALLENGE




#include<bits/stdc++.h>

// GHADI DETERGENT..

// PEHLE ISTEMAAL KAREIN FIR VISHWAAS KAREIN..

// HAPPY NEW YEAR..


using namespace std;

long long MOD;
long long MAXX = 1000000009;
int mukhya_kaarak[10000011] = {0};
long long arr[100015];
long long khand_vraksh[4 * 100015];
long long sq[5];

void Lowest_Prime_Factors(){
	long long i, j;
	for(i=2; i<=10000000; i+=2){
		mukhya_kaarak[i] = 2;
	}
	for(i=3; i<=10000000; i+=2){
		if(mukhya_kaarak[i] == 0){
			mukhya_kaarak[i] = i;
			for(j=i; (i*j)<10000000; j+=2){
				if(mukhya_kaarak[i*j] == 0){
					mukhya_kaarak[i*j] = i;
				}
			}
		}
	}
	mukhya_kaarak[1] = 1;
}

typedef long long int LLI;

//----------------UTILITY FUNCTIONS TO PERFORM MODULO ARITHMATIC ON NUMBERS----------//
inline int
addMod( int a, int b){
	LLI v=a;
	v+=b;
	if(v>=MOD) v-=MOD;
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
//=====================================================================================//



long long modularMult(long long a, long long b){
    if(MOD <= MAXX)
        return a * b% MOD;
    long long res = 0;
    while(a>0){
        if(a & 1) {
            res += b;
            if(res >= MOD)
                res = res - MOD;
        }
        a >>= 1;
        b <<= 1;
        if(b >= MOD)
            b = b-MOD;
    }
    return res;
}

int isPerfectSquare(long long N, int itr){
    long long x = sqrt(N);
    if(x*x == N){
        sq[itr] = x;
        return 1;
    }
    return 0;
}

int isSumOfTwoSquares(long long N){
    // ANY NUMBER WHOSE COUNT ALL PRIME FACTORS OF THE
    // FORM 4K+3 ARE EVEN, CAN BE REPRESENTED AS SUM OF
    // TWO SQUARES..

    // THIS TOO WAS SAID BY A LEGEND, AND I TRUST HIM
    // LETS TRY..

     int counter;
     while(N > 1){

        // I AM A DUDE AND MADE IT WORK IN LOG(N)..

        long long lowestPrimeFactor = mukhya_kaarak[N];
        counter = 0;
        while(N % lowestPrimeFactor == 0){
            N = N/lowestPrimeFactor;
            counter++;
        }

        // CHECK THE SAYINGS OF THE LEGEND..
        if(lowestPrimeFactor % 4 == 3 && counter%2 == 1)
            return 0;
    }
    return 1;
}

// AS I ALWAYS ADD A TIME-PASS FUNCTION TO MY CODE.. HERE IT GOES..

void printAletter(char * nameOfGirl){

    printf("Hello!\n");
    printf("Dear %s,",nameOfGirl);
    printf("If there is anything more honorable than this I would bestow u with that too.. words wont be able to define the bond I share with u dear friend...u add life to my dull and boring days...much love dear friend..thankyou for being in my life..a true blessing u are!!!\n\n\nThank you for being there for me when I call you and need someone to just listen. It doesn’t matter where we are in this world or in our lives, I know you will always pick me.\n\n\n\nwords cant describe how much i value u, u ve been mre dan a best friend to me...you deserve more than a Gold medal...i heart u plenty plenty.");

    return;
}

void TimePass(int n){

    char nameOfGirl[25];
    while(1){
        scanf("%s",nameOfGirl);
        printAletter(nameOfGirl);
    }

    // DID YOU NOTICE I DIDN'T DO ANYTHING WITH n..
    return;
}


int FindThreeSquares(long long N, int num){
    if(num == 0)
        return N==0;
    if(N==1){
        sq[num-1] = 1;
        return 1;
    }
    if(N==0)
        return 1;
    if(num==1)
        return isPerfectSquare(N, num-1);
    int isEven = 0;
    long long Pow = 1;

    if(num==2){
        while(N%4==0){
            N/=4;
            Pow = Pow * 2;
        }
        if(N%2 == 0){
            isEven = 1;
            N=N/2;
        }

        // CHECK IF CAN BE REPRESENTED AS SUM OF
        // TWO SQUARES..
        if(N <= 10000000){
            if(!isSumOfTwoSquares(N))
                return 0;
        }
    }

    int smallAns = 0;
    long long candidate = sqrt(N);
    for(int i=candidate; i>=1; i--){
        sq[num-1] = i;
        smallAns = FindThreeSquares(N - (long long)i * i, num-1);
        if(smallAns){
            // yess!! *_* we found the answer!!!!!!
            if(num == 2){
                if(isEven){
                    long long A = sq[0];
                    long long B = sq[1];
                    sq[0] = A+B;
                    sq[1] = abs(A-B);
                }
                sq[0] = Pow * sq[0];
                sq[1] = Pow * sq[1];
            }
            break;
        } else{
            sq[num-1] = 0;
        }
    }
    return smallAns;
}
void khand_vraksh_ka_nirmaan(int i, int s, int e){
	if(s==e){
		khand_vraksh[i] = arr[s];
		return;
	}
	int baayein = 2*i; int daayein = 2*i + 1; int madhya = (s+e)/2;
	khand_vraksh_ka_nirmaan(baayein, s, madhya);
	khand_vraksh_ka_nirmaan(daayein, madhya+1, e);
	khand_vraksh[i] = modularMult(khand_vraksh[baayein], khand_vraksh[daayein]);
}

long long prashn(int i, int s, int e, long long x, long long y){
	if(s > y || e < x || s > e)
		return 1;
	if(e <= y && s >=x)
		return khand_vraksh[i];
	int baayein = 2*i; int daayein = 2*i + 1;
	int mid = (s+e)/2;
	return modularMult( prashn(baayein, s, mid, x, y), prashn(daayein, 1+mid, e, x, y) );
}

void adhyatan(int i, int s, int e, long long x, long long y){
	if(s==e){
		if(s == x){
            khand_vraksh[i] = y;
		}
		return;
	}
	if(s > e || e < x || x < s) return;
	int baayein = 2*i; int daayein = 2*i+1;
	int mid = (s+e)/2;
	adhyatan(baayein, s, mid, x, y);
	adhyatan(daayein, 1+mid, e, x, y);
	khand_vraksh[i] = modularMult(khand_vraksh[baayein], khand_vraksh[daayein]);
}

void Solve(long long N){
    sq[0] = 0; sq[1] = 0; sq[2] = 0; sq[3] = 0;
    if(N==0) return;
    long long Pow = 1;
    int isEven=0;
    while(N%4==0){
        N = N/4;
        Pow = 2*Pow;
    }
    if(N%2 == 0){
        isEven = 1;
        N= N/2;
    }

    // ANY NUMBER OF THE FORM 4^A * (8K + 7)
    // CANNOT BE REPRESENTED AS SUM OF THREE SQUARES..
    // SOME LEGEND SAID THIS, AND I TRUST HIM..

    if(N%8==7){
        // FOURTH SQUARE BE 1..
        sq[3] = 1;
        FindThreeSquares(N-1, 3);
    } else{
        FindThreeSquares(N, 3);
    }

    if(isEven){
        long long A = sq[0];
        long long B = sq[1];
        long long C = sq[2];
        long long D = sq[3];

        sq[0] = A+B;
        sq[1] = abs(A-B);
        sq[2] = C+D;
        sq[3] = abs(C-D);

    }

    sq[0] = Pow * sq[0];
    sq[1] = Pow * sq[1];
    sq[2] = Pow * sq[2];
    sq[3] = Pow * sq[3];
}

void solve(int n, int q){

    // Build The Segment Tree
    khand_vraksh_ka_nirmaan(1, 0, n-1);
    int type; long long l, r;
    while(q--){
        scanf("%d%lld%lld",&type, &l, &r);
        if(type==1)
            adhyatan(1, 0, n-1, l-1, r);
        else{
            long long Product = prashn(1, 0, n-1, l-1, r-1);
            Solve(Product);
            printf("%lld %lld %lld %lld\n",sq[0], sq[1], sq[2], sq[3]);
        }
    }

}
int main(){
    Lowest_Prime_Factors();
    int t, n, q;
    long long p;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%lld",&n,&q,&p);
        MOD = p;
        for(int i=0; i<n; i++)
            scanf("%lld",&arr[i]);
        solve(n, q);
    }
    return 0;
}


// MUJH PAR EK EHSAAN KARNA KI MUJHPAR KOI EHSAAN NA KARNA

/*


	hud hud dabang dabang dabang..


*/



/*

// HIMANSHU TIWARI
// XARINIOV9


// JAN'17 LONG CHALLENGE

#include<stdio.h>


// GHADI DETERGENT..

// PEHLE ISTEMAAL KAREIN FIR VISHWAAS KAREIN..

// HAPPY NEW YEAR..

void solve(int C, int D, int L){
    L -= D*4;
    if(L%4 || L<0){
        printf("no\n");
        return;
    } else {
        L/=4;
        if(L<=C && C-L <= 2*D){
            printf("yes\n");
            return;
        }
        printf("no\n");
    }
    return;
}

// AS I ALWAYS ADD A TIME-PASS FUNCTION TO MY CODE.. HERE IT GOES..

void printAletter(char * nameOfGirl){

    printf("Hello!\n");
    printf("Dear %s,",nameOfGirl);
    printf("If there is anything more honorable than this I would bestow u with that too.. words wont be able to define the bond I share with u dear friend...u add life to my dull and boring days...much love dear friend..thankyou for being in my life..a true blessing u are!!!\n\n\nThank you for being there for me when I call you and need someone to just listen. It doesn’t matter where we are in this world or in our lives, I know you will always pick me.\n\n\n\nwords cant describe how much i value u, u ve been mre dan a best friend to me...you deserve more than a Gold medal...i heart u plenty plenty.");

    return;
}

void TimePass(int n){

    char nameOfGirl[25];
    while(1){
        scanf("%s",nameOfGirl);
        printAletter(nameOfGirl);
    }

    // DID YOU NOTICE I DIDN'T DO ANYTHING WITH n..
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long Cats, Dogs, Legs;
        scanf("%lld%lld%lld",&Cats,&Dogs,&Legs);
        solve(Cats, Dogs, Legs);
    }
    return 0;
}


*/
