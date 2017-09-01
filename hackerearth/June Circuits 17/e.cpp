#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        int i=1;
        while(i*i <= x){
            i++;
        }
        i--;

        int rem = x - (i*i);
        string s(i, '(');
        string s1(i, ')');

        string initial = s+s1;

        if(rem >= i){
            initial += ')';
            rem -= i;
        }
        if(rem == i){
            initial += ')';
            rem -= i;
        }
        if(rem == 0){
            cout<<initial<<endl;
        }
        if(rem > 0){
            int n = initial.size() - rem;
            string Final = initial.substr(0, rem);
            Final += ')';
            Final += initial.substr(rem, n);
            cout<<Final<<endl;
        }
    }
    return 0;
}
