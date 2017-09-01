#include<bits/stdc++.h>

#define undf -1

using namespace std;

char str[2][100010];

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",str[0]);

    for(int i=0; i<2*n; i+=2){
        int cl[4] = {0};
        int c1 = undf, c2 = undf;
        cl[str[0][i] - 'A'] = 1;
        cl[str[0][i+1] - 'A'] = 1;

        for(int j=0; j<4; j++){
            if(cl[j] == 0){
                if(c1 == undf){
                    c1 = j + 'A';
                } else
                    c2 = j + 'A';
            }
        }
        if(i != 0 && str[1][i-1] == c1){
            str[1][i] = c2;
            str[1][i+1] = c1;
        } else {
            str[1][i] = c1;
            str[1][i+1] = c2;
        }

    }
    cout<<str[1];
}
