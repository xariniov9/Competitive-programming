// HIMANSHU TIWARI
// XARINIOV9


// JAN'17 LONG CHALLENGE



#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>

// GHADI DETERGENT..

// PEHLE ISTEMAAL KAREIN FIR VISHWAAS KAREIN..

// HAPPY NEW YEAR..

using namespace std;

vector<pair<double, double> > points(555);

double pi = acos(-1.0);

double distanceBetween(const pair<double, double>&a, const pair<double, double>&b){
    return sqrt( ((a.first - b.first) * (a.first - b.first)) + ((a.second - b.second) * (a.second - b.second)));
}

long long MOD;
long long MAXX = 1000000009;

vector < pair<double, bool> > A(251234);
bool cmp(const pair<double, bool>&i, const pair<double, bool>&j){
    return i.first < j.first;
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
int MaximumPoints(int n, double R){
    int answer = 0;
    double th, ph, dis;
    for(int i=0; i<n; i++){
        int itr=0, sum=0;
        for(int j=0; j<n; j++){
            if(i!=j && ((dis = distanceBetween(points[i], points[j])) <= 2.0 * R) ){
                th = atan2(points[j].second - points[i].second, points[j].first - points[i].first);
                if(th < 0)  th += 2 * pi;
                ph = acos(dis/(2.0*R));
                A[itr].first = th - ph+2*pi;
                A[itr + 1].first = th + ph + 2*pi;
                A[itr].second = true; A[itr+1].second = false;
                itr+=2;
            }
        }
        sort(A.begin(), A.begin()+itr, cmp);
        for(int j=0; j<itr; j++){
            sum = (A[j].second == true) ? sum+1 : sum-1;
            answer = max(answer, sum);
        }
    }
    return answer+1;
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

double solve(double l, double r, int m, int N){
    double md; int n;
    while( (r-l) > 0.001){
        md = (l+r)/2.0;
        n=MaximumPoints(N, md);
       // printf("iter : %lf %d\n",md, MaximumPoints(N, md));
        if(n < m) l = md;
        else      r = md;
    }
    return md;
}

int main(){
    int n, m;
    double x, y;
    scanf("%d %d",&n, &m);
    for(int i=0; i<n; i++){
        scanf("%lf %lf",&x, &y);
        points[i].first = x;
        points[i].second = y;
    }
    double R = solve(0, 3.0 * 1000, m, n);
    printf("%.3lf\n",R);
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
