#include<stdio.h>
#include<string.h>

typedef struct Team{
    char * name;
    int rank;
} team;

team T[1000005];

char str[100000];

int comp(const void * A, const void * B){
    int f = ((team *)A)->rank;
    int s = ((team *)B)->rank;

    return f-s;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, i;
        scanf("%d",&n);
        for(i=0; i<n; i++){
            scanf("%s",str);
            scanf("%d",&T[i].rank);
            T[i].name = strdup(str);
        }
        qsort(T, n, sizeof(team), comp);
        long long ans = 0;
        for(i=0; i<n; i++){
            ans = ans  + (long long)abs((i+1) - T[i].rank);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
