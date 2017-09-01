#include<bits/stdc++.h>

using namespace std;

long long bitmask[2505][50];
int sze[2505];
//unsigned long long lim=0;

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        int n, sz, itm, k;
        scanf("%d%d",&n,&k);

        memset(bitmask, 0, sizeof bitmask);
        memset(sze, 0, sizeof sze);
        for(int i=0; i<n; i++){
            scanf("%d",&sz);
            sze[i] = sz;
            for(int j=0; j<sz; j++){
                scanf("%d",&itm);
                itm--;
                bitmask[i][itm/60] |= (long long)1<<(itm%60);
            }
        }


        int ans = 0;
        int ub = k/60;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(sze[i] + sze[j] < k)
                    continue;
                int itms = 0;
                for(int kk=0; kk<ub; kk++){
                    int c =  __builtin_popcountll(bitmask[i][kk] | bitmask[j][kk]);
                    itms += c;
                    if(c<60)
                        break;
                }
                for(int kk=ub; kk<=ub+1; kk++)
                    itms += __builtin_popcountll(bitmask[i][kk] | bitmask[j][kk]);
                if(itms == k)
                    ans++;

            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


/*
1
2 62
60 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60
2 61 62

mask : 1152921504606846975 0
mask : 0 3

*/
