#include<bits/stdc++.h>

using namespace std;
//a+b=c
char s1[20], s2[20], s3[20], s4[20], s5[20];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int f1=0, f2=0, f3=0;
        scanf("%s%s%s%s%s",s1, s4, s2, s5, s3);
        //cout<<s1<<s4<<s2<<s5<<s3;
        for(int i=0; i<strlen(s1); i++){
            if(s1[i] < '0' || s1[i] > '9')
                f1 = 1;
        }
        for(int i=0; i<strlen(s2); i++){
            if(s2[i] < '0' || s2[i] > '9')
                f2 = 1;
        }
        for(int i=0; i<strlen(s3); i++){
            if(s3[i] < '0' || s3[i] > '9')
                f3 = 1;
        }
        int o1=0, o2=0, o3=0;
        if(f3){
            for(int i=0; i<strlen(s2); i++)
                o2 = 10 * o2 + (s2[i] - '0');
            for(int i=0; i<strlen(s1); i++)
                o1 = 10 * o1 + (s1[i] - '0');
            o3 = o1 + o2;
        }
        if(f2){
            for(int i=0; i<strlen(s3); i++)
                o3 = 10 * o3 + (s3[i] - '0');
            for(int i=0; i<strlen(s1); i++)
                o1 = 10 * o1 + (s1[i] - '0');
            o2 = o3 - o1;
        }
        if(f1){
            for(int i=0; i<strlen(s3); i++)
                o3 = 10 * o3 + (s3[i] - '0');
            for(int i=0; i<strlen(s2); i++)
                o2 = 10 * o2 + (s2[i] - '0');
            o1 = o3 - o2;
        }
        printf("%d + %d = %d\n",o1, o2, o3);
    }
    return 0;
}
