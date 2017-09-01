#include<bits/stdc++.h>

#define MaxStps 20
#define MaxN 200005


using namespace std;
char str[200005];
int P[MaxStps][MaxN];

vector<pair<int, pair<int, int> > > L(MaxN);

bool cmp(const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > &b){

    return a.second.first == b.second.first ? (a.second.second < b.second.second ? 1:0) :
                                                (a.second.first < b.second.first ? 1 : 0);

}

int arr[MaxN + 5];
int n;
void FindSuffixArray(){

    int stp = 0;
    for(int i=0; i<n; i++)
        P[stp][i] = str[i] - 'a'; //change if upper case chars

    stp++;
    int cnt = 1;

    while(cnt < n){
        for(int i=0; i<n; i++)
            L[i] = (make_pair(i, make_pair(P[stp-1][i], i+cnt < n ? P[stp-1][i+cnt] : 10000000)));

        sort(L.begin(), L.begin()+n, cmp);

        for(int i=0; i<n; i++){
            P[stp][L[i].first] = i>0 &&
                            L[i-1].second.first == L[i].second.first &&
                            L[i-1].second.second == L[i].second.second ?
                            P[stp][L[i-1].first] : i;

        }
        stp++;
        cnt *= 2;
    }
    int pos = ceil(log(n)/log(2));
    for(int i=0;i<n;i++)
        arr[P[pos][i]] = i;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        n= strlen(str);
        for(int i=0; i<n; i++)
            str[i+n] = str[i];
        str[2*n] = '\0';
        n = 2*n;
        FindSuffixArray();

        //for(int i=0; i<n; i++)
           // printf("%d ",L[i].first);
        //printf("\n");

        printf("%d\n",arr[0]);

    }
    return 0;
}

