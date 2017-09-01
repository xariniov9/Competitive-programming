// HIMANSHU TIWARI
// XARINIOV9


// JAN'17 LONG CHALLENGE

#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

// GHADI DETERGENT..

// PEHLE ISTEMAAL KAREIN FIR VISHWAAS KAREIN..

// HAPPY NEW YEAR..

using namespace std;
vector<vector<int> > city(51234);

vector<pair<int, int> > population(51234);

typedef long long int LLI;

long long MOD = 10000;
long long MAXX = 10;
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

void Clear(int n){
    for(int i=0; i<=n; i++)
        city[i].clear();
}

int Rank[51234];

void readInput(int n){
    int popi, u, v;

    // population
    for(int i=0; i<n; i++){
        scanf("%d",&popi);
        population[i].first = i+1;
        population[i].second = popi;
    }

    // graph
    for(int i=0; i<n-1; i++){
        scanf("%d%d",&u,&v);
        city[u].push_back(v);
        city[v].push_back(u);
    }
}

bool cmp(const pair<int, int>&i, const pair<int, int>&j){
    return i.second > j.second;
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

void solve(int n){
    sort(population.begin(), population.begin() + n, cmp);

    //Calculate rank of each city..
    for(int i=0; i<n; i++)
        Rank[population[i].first] = i+1;

    //Solving..
    for(int i=1; i<=n; i++){
        //Pushing all corresponding ranks in pq
        priority_queue<int, vector<int>, greater<int> > pq;
        pq.push(Rank[i]);
        for(int j=0; j<city[i].size(); j++)
            pq.push(Rank[city[i][j] ]);

        int minimumRank, ans=1;
        while(!pq.empty()){
            minimumRank = pq.top();
            pq.pop();
            if(ans != minimumRank){
                printf("%d ",population[ans-1].first);
                break;
            }
            ans++;
        }
        if(ans == n+1 || ans == minimumRank+1){
            if(ans == n+1)
                printf("0 ");
            else
                printf("%d ",population[ans-1].first);
        }
    }
    printf("\n");
}

int main(){
    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        Clear(n);
        readInput(n);
        solve(n);
    }
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
