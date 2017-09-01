// HIMANSHU TIWARI
// XARINIOV9


// JAN'17 LONG CHALLENGE

#include<stdio.h>

#define Water 1
#define Brick 2
#define Air 3

// GHADI DETERGENT..

// PEHLE ISTEMAAL KAREIN FIR VISHWAAS KAREIN..

// HAPPY NEW YEAR..

int Reservoi[1005][1005];
char str[1005];

void readInput(int n, int m){
    for(int i=0; i<n; i++){
        scanf("%s",str);
        for(int j=0; j<m; j++){
            if(str[j] == 'W')
                Reservoi[i][j] = Water;
            else if(str[j] == 'B')
                Reservoi[i][j] = Brick;
            else
                Reservoi[i][j] = Air;
        }
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

int isStable(int n, int m){
    int isOk = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((j==0 || j== m-1) && (Reservoi[i][j] == Water)){
                isOk = 0;
                return isOk;
            }
            if(Reservoi[i][j] == Water &&
               (Reservoi[i][j-1] == Air || Reservoi[i][j+1] == Air)){
                isOk = 0;
                return isOk;
            }
            if(i < n-1 &&(Reservoi[i][j] == Brick || Reservoi[i][j] == Water)
                        && Reservoi[i+1][j] == Air){
                isOk = 0;
                return isOk;
            }
            if(i<n-1 && Reservoi[i][j] == Brick
                    && Reservoi[i+1][j] == Water){
                isOk = 0;
                return isOk;
            }
        }
    }
    return isOk;
}

int main(){
    int t, n, m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        readInput(n, m);
        if(isStable(n, m))
            printf("yes\n");
        else printf("no\n");
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
