#include<stdio.h>

int cnt = 0;

void two(int i, int j, int hor){
    if(hor){
        printf("%d %d %d %d\n",i, j, i, j+1);
    } else{
        printf("%d %d %d %d\n",i, j, i+1, j);
    }
    cnt++;
}

//7
void four(int i, int j, int hor){
    if(hor){
        two(i, j, hor);
        two(i, j+2, hor);
        cnt += 5;
        printf("%d %d %d %d\n",i, j+1, i, j+2);
        printf("%d %d %d %d\n",i, j  , i, j+1);
        printf("%d %d %d %d\n",i, j+1, i, j+2);
        printf("%d %d %d %d\n",i, j  , i, j+1);
        printf("%d %d %d %d\n",i, j+2, i, j+3);
    } else{
        two(i, j, hor);
        two(i+2, j, hor);
        cnt += 5;
        printf("%d %d %d %d\n",i+1, j, i+2, j);
        printf("%d %d %d %d\n",i,   j, i+1, j);
        printf("%d %d %d %d\n",i+1, j, i+2, j);
        printf("%d %d %d %d\n",i,   j, i+1, j);
        printf("%d %d %d %d\n",i+2, j, i+3, j);
    }
}

//14
void five(int i, int j, int hor){
    if(hor){
        four(i, j, hor);
        cnt += 7;
        printf("%d %d %d %d\n",i, j+3, i, j+4);
        printf("%d %d %d %d\n",i, j+2, i, j+3);
        printf("%d %d %d %d\n",i, j+1, i, j+2);
        printf("%d %d %d %d\n",i, j  , i, j+1);
        printf("%d %d %d %d\n",i, j+1, i, j+2);
        printf("%d %d %d %d\n",i, j  , i, j+1);
        printf("%d %d %d %d\n",i, j+2, i, j+3);
    } else {
        four(i, j, hor);
        cnt += 7;
        printf("%d %d %d %d\n",i+3, j, i+4, j);
        printf("%d %d %d %d\n",i+2, j, i+3, j);
        printf("%d %d %d %d\n",i+1, j, i+2, j);
        printf("%d %d %d %d\n",i,   j, i+1, j);
        printf("%d %d %d %d\n",i+1, j, i+2, j);
        printf("%d %d %d %d\n",i,   j, i+1, j);
        printf("%d %d %d %d\n",i+2, j, i+3, j);
    }
}

//31
void eight(int i, int j, int hor){
    if(hor){
        four(i, j, hor);
        four(i, j+4, hor);
        cnt += 3;
        printf("%d %d %d %d\n",i, j+3, i, j+4);
        printf("%d %d %d %d\n",i, j+2, i, j+3);
        printf("%d %d %d %d\n",i, j+4, i, j+5);
        four(i, j, hor);
        four(i, j+4, hor);
    } else {
        four(i, j, hor);
        four(i+4, j, hor);
        cnt += 3;
        printf("%d %d %d %d\n",i+3, j, i+4, j);
        printf("%d %d %d %d\n",i+2, j, i+3, j);
        printf("%d %d %d %d\n",i+4, j, i+5, j);
        four(i, j, hor);
        four(i+4, j, hor);
    }
}

//7
void fiveReverse(int i, int j, int hor){
    if(hor){
        cnt += 7;
        printf("%d %d %d %d\n",i, j  , i, j+1);
        printf("%d %d %d %d\n",i, j+1, i, j+2);
        printf("%d %d %d %d\n",i, j+2, i, j+3);
        printf("%d %d %d %d\n",i, j+3, i, j+4);
        printf("%d %d %d %d\n",i, j+2, i, j+3);
        printf("%d %d %d %d\n",i, j+1, i, j+2);
        printf("%d %d %d %d\n",i, j+3, i, j+4);
    } else {
        cnt += 7;

        printf("%d %d %d %d\n",i,   j, i+1, j);
        printf("%d %d %d %d\n",i+1, j, i+2, j);
        printf("%d %d %d %d\n",i+2, j, i+3, j);
        printf("%d %d %d %d\n",i+3, j, i+4, j);
        printf("%d %d %d %d\n",i+2, j, i+3, j);
        printf("%d %d %d %d\n",i+1, j, i+2, j);
        printf("%d %d %d %d\n",i+3, j, i+4, j);
    }

}

//58
void ten(int i, int j, int hor){
    // 31 +7 + 13 +7
    if(hor){
        four(i, j+6, hor);
        eight(i, j, hor);
        //printf("%d %d %d %d\n",i, j+8, i, j+9);
        cnt += 13;
        printf("%d %d %d %d\n",i, j+7, i, j+8);
        printf("%d %d %d %d\n",i, j+8, i, j+9);
        printf("%d %d %d %d\n",i, j+6, i, j+7);
        printf("%d %d %d %d\n",i, j+5, i, j+6);
        printf("%d %d %d %d\n",i, j+4, i, j+5);
        printf("%d %d %d %d\n",i, j+6, i, j+7);

        printf("%d %d %d %d\n",i, j+3, i, j+4);
        printf("%d %d %d %d\n",i, j+2, i, j+3);
        printf("%d %d %d %d\n",i, j+1, i, j+2);
        printf("%d %d %d %d\n",i, j  , i, j+1);
        printf("%d %d %d %d\n",i, j+1, i, j+2);
        printf("%d %d %d %d\n",i, j  , i, j+1);
        printf("%d %d %d %d\n",i, j+2, i, j+3);
        fiveReverse(i, j+5, hor);
    } else {
        four(i+6, j, hor);
        eight(i, j, hor);
       // printf("%d %d %d %d\n",i+8, j, i+9, j);
        cnt += 13;
        printf("%d %d %d %d\n",i+7, j, i+8, j);
        printf("%d %d %d %d\n",i+8, j, i+9, j);
        printf("%d %d %d %d\n",i+6, j, i+7, j);
        printf("%d %d %d %d\n",i+5, j, i+6, j);
        printf("%d %d %d %d\n",i+4, j, i+5, j);
        printf("%d %d %d %d\n",i+6, j, i+7, j);

        printf("%d %d %d %d\n",i+3, j, i+4, j);
        printf("%d %d %d %d\n",i+2, j, i+3, j);
        printf("%d %d %d %d\n",i+1, j, i+2, j);
        printf("%d %d %d %d\n",i,   j, i+1, j);
        printf("%d %d %d %d\n",i+1, j, i+2, j);
        printf("%d %d %d %d\n",i,   j, i+1, j);
        printf("%d %d %d %d\n",i+2, j, i+3, j);
        fiveReverse(i+5, j, hor);
    }
}

//58 + 14 + 12
void eleven(int i, int j, int hor){
    if(hor){
        ten(i, j, hor);
        five(i, j+6, hor);
        cnt += 12;
        printf("%d %d %d %d\n",i, j+5, i, j+6);
        printf("%d %d %d %d\n",i, j+4, i, j+5);
        printf("%d %d %d %d\n",i, j+5, i, j+6);
        printf("%d %d %d %d\n",i, j+4, i, j+5);
        printf("%d %d %d %d\n",i, j+5, i, j+6);

        printf("%d %d %d %d\n",i, j+3, i, j+4);
        printf("%d %d %d %d\n",i, j+2, i, j+3);
        printf("%d %d %d %d\n",i, j+1, i, j+2);
        printf("%d %d %d %d\n",i, j  , i, j+1);
        printf("%d %d %d %d\n",i, j+1, i, j+2);
        printf("%d %d %d %d\n",i, j  , i, j+1);
        printf("%d %d %d %d\n",i, j+2, i, j+3);
    } else {
        ten(i, j, hor);
        five(i+6, j, hor);

        cnt += 12;
        printf("%d %d %d %d\n",i+5, j, i+6, j);
        printf("%d %d %d %d\n",i+4, j, i+5, j);
        printf("%d %d %d %d\n",i+5, j, i+6, j);
        printf("%d %d %d %d\n",i+4, j, i+5, j);
        printf("%d %d %d %d\n",i+5, j, i+6, j);

        printf("%d %d %d %d\n",i+3, j, i+4, j);
        printf("%d %d %d %d\n",i+2, j, i+3, j);
        printf("%d %d %d %d\n",i+1, j, i+2, j);
        printf("%d %d %d %d\n",i,   j, i+1, j);
        printf("%d %d %d %d\n",i+1, j, i+2, j);
        printf("%d %d %d %d\n",i,   j, i+1, j);
        printf("%d %d %d %d\n",i+2, j, i+3, j);
    }
}

void thirteen(int i, int j, int hor){
    if(hor){
        four(i, j+9, hor);
        eleven(i, j, hor);
        cnt += 4;
        printf("%d %d %d %d\n",i, j+10, i, j+11);
        printf("%d %d %d %d\n",i, j+11, i, j+12);
        printf("%d %d %d %d\n",i, j+10, i, j+11);
        printf("%d %d %d %d\n",i, j+11, i, j+12);
        eleven(i, j, hor);
    } else {
        four(i+9, j, hor);
        eleven(i, j, hor);
        cnt += 4;
        printf("%d %d %d %d\n",i+10, j, i+11, j);
        printf("%d %d %d %d\n",i+11, j, i+12, j);
        printf("%d %d %d %d\n",i+10, j, i+11, j);
        printf("%d %d %d %d\n",i+11, j, i+12, j);
        eleven(i, j, hor);
    }
}

int sixteen(int i, int j, int hor){
    if(hor){
        four(i, j+12, hor);
        thirteen(i, j, hor);
        printf("%d %d %d %d\n",i, j+12, i, j+13);
        printf("%d %d %d %d\n",i, j+13, i, j+14);
        printf("%d %d %d %d\n",i, j+12, i, j+13);
        cnt+=3;
        five(i, j+11, hor);
    } else {
        four(i+12, j, hor);
        thirteen(i, j, hor);
        printf("%d %d %d %d\n",i+12, j, i+13, j);
        printf("%d %d %d %d\n",i+13, j, i+14, j);
        printf("%d %d %d %d\n",i+12, j, i+13, j);
        cnt += 3;
        five(i+11, j, hor);
    }
}

int twenty(int i, int j, int hor){
    if(hor){
        eleven(i, j+9, hor);
        eleven(i, j, hor);
        printf("%d %d %d %d\n",i, j+10, i, j+11);
        printf("%d %d %d %d\n",i, j+11, i, j+12);
        printf("%d %d %d %d\n",i, j+12, i, j+13);
        printf("%d %d %d %d\n",i, j+11, i, j+12);
        printf("%d %d %d %d\n",i, j+10, i, j+11);
        printf("%d %d %d %d\n",i, j+12, i, j+13);
        cnt += 6;
        sixteen(i, j+1, hor);
        sixteen(i, j+4, hor);
    } else {
        eleven(i+9, j, hor);
        eleven(i, j, hor);
        printf("%d %d %d %d\n",i+10, j, i+11, j);
        printf("%d %d %d %d\n",i+11, j, i+12, j);
        printf("%d %d %d %d\n",i+12, j, i+13, j);
        printf("%d %d %d %d\n",i+11, j, i+12, j);
        printf("%d %d %d %d\n",i+10, j, i+11, j);
        printf("%d %d %d %d\n",i+12, j, i+13, j);
        cnt += 6;
        sixteen(i+1, j, hor);
        sixteen(i+4, j, hor);
    }

}
int main(){

    int n;
    scanf("%d",&n);
    if(n==2){
        printf("4\n");
        two(1, 1, 1);
        two(2, 1, 1);
        two(1, 1, 0);
        two(1, 2, 0);
    } else if(n==4){
        printf("56\n");
        for(int i=1; i<=4; i++){
            four(i, 1, 1);
        }
        for(int j=1; j<=4; j++){
            four(1, j, 0);
        }
    } else if(n==5){
        printf("140\n");
        for(int i=1; i<=5; i++){
            five(i, 1, 1);
        }
        for(int j=1; j<=5; j++){
            five(1, j, 0);
        }
    } else if(n==8){
        printf("496\n");
        cnt = 0;
        for(int i=1; i<=8; i++){
            eight(i, 1, 1);
        }
        for(int j=1; j<=8; j++){
            eight(1, j, 0);
        }
       // printf("COUNT %d\n",cnt );
    }else if(n==11){
        printf("1848\n");
        cnt = 0;
        for(int i=1; i<=11; i++){
            eleven(i, 1, 1);
        }
        for(int j=1; j<=11; j++){
            eleven(1, j, 0);
        }
        //printf("COUNT %d\n",cnt );
    } else if(n==13){
        cnt = 0;
        printf("4654\n");

        for(int i=1; i<=13; i++){
            thirteen(i, 1, 1);
        }
        for(int j=1; j<=13; j++){
            thirteen(1, j, 0);
        }
        //printf("COUNT %d\n",cnt );
    } else if(n==16){
        cnt = 0;
        printf("6496\n");

        for(int i=1; i<=16; i++){
            sixteen(i, 1, 1);
        }
        for(int j=1; j<=16; j++){
            sixteen(1, j, 0);
        }
        //printf("COUNT %d\n",cnt );
    } else if(n==20){
        cnt = 0;
        printf("23200\n");

        for(int i=1; i<=20; i++){
            twenty(i, 1, 1);
        }
        for(int j=1; j<=20; j++){
            twenty(1, j, 0);
        }
       // printf("COUNT %d\n",cnt );
    }
    return 0;

}
