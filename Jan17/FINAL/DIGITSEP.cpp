// HIMANSHU TIWARI
// XARINIOV9


// JAN'17 LONG CHALLENGE


/*

    I liked this problem..
    I used recursion.. added memoisation with vector of vector of maps (wtf?)
    Added pruning as new numbers are added, gcd will be non decreasing..
    No tree can have ans more than gcdSofar and kept checking with global ans

    It is kind of branch and bound with memoization, but its koooool !


*/
#include<cstdio>
#include<map>
#include<vector>
#include<iterator>
#include<algorithm>

// GHADI DETERGENT..

// PEHLE ISTEMAAL KAREIN FIR VISHWAAS KAREIN..

// HAPPY NEW YEAR..

using namespace std;

long long MOD;
long long MAXX = 1000000009;

char s[3];

long long globalAns;


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
// WTF ? MAP for dp.. 300 * 300 * 10^10..
// LET'S SEE WHAT HAPPENS.. LOL
vector<vector<map<long long, long long> > > table(1, vector<map<long long, long long> >(1));

// IN CASE WE NEED ITS ITERATOR..
map<long long, long long>:: iterator itr;

bool comparator(const pair<int, long long>&i, const pair<int, long long>&j){
    if(i.second == j.second)
        return i.first < j.first;
    return i.second > j.second;
}


/*

    The idea is memoising along with branch and bound..
    The main principle is gcd(a, b) <= min(a, b)

*/



void clearDP(int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++)
            table[i][j].clear();
    }
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

long long solve(int n){
    clearDP(n);
    globalAns = -1;
    int x, y;
    x = x+1; y = y+1;
    return  0;
}

vector< int> randsX;
vector< int> randsY;


void random_number(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(200, 5000-200);
    for(int i =0; i<=200; i++)
        randsX.push_back(dis(gen));
    for(int i =0; i<=200; i++)
        randsY.push_back(dis(gen));

}
int main(){
    int n, s, skip, x, y;
    scanf("%d%d%d",&n,&s,&skip);
    for(int i=0; i<2*n; i++){
        scanf("%d",&x);
    }
    int r;
    int itr = 0;
    random_number();
    for(int i=0; i<n; i++){
               scanf("%d",&r);

        x = randsX[i];
        y = randsY[i];
        if (r > x)
            x = r;
        if( x > s-r )
            x = (s-r);
        if(y < r)
            y = r;
        if(y > s-r)
            y = s-r;
        printf("%d %d\n",x, y);
         fflush(stdout);
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
