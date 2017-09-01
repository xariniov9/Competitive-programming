#include <bits/stdc++.h>

using namespace std;

string s;

int Pow[1000000];

void power(int n, int b, int m){
    Pow[0] = 1;
    for(int i=1; i<=n; i++){
        Pow[i] = Pow[i-1] * b;
        if(Pow[i] >= m)
            Pow[i] %= m;
    }
}

int getMagicNumber(string s, int k, int b, int m){
    int ans = 0;
    int mult = 0;
    int n= s.size();
    power(k, b, m);

    for(int i=0; i<k; i++){
        mult += (s[i] - '0') * Pow[k-i-1];
        if(mult >= m)
            mult %= m;
    }
  //  printf("%d ",mult);
    ans += mult;

    for(int i=0; i<n-k; i++){
        mult -= ((s[i] - '0') * Pow[k-1])%m;
        if(mult < 0)
            mult += m;
        mult = ((mult * b) + s[i+k] - '0') %m;
       // printf("%d ",mult);

        ans += mult;
    }
//    printf("\n");
    return ans;
}

int main() {
    cin >> s;
    int k;
    int b;
    int m;
    cin >> k >> b >> m;
    int result = getMagicNumber(s, k, b, m);
    cout << result << endl;
    return 0;
}

