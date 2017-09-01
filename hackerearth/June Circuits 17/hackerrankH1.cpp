#include<bits/stdc++.h>

using namespace std;

string compress(string str){
    string res;
    int n = str.size();
    int i=0;
    while(i<n){
        int j=i+1;
        int cnt = 1;
        while(j<n && str[i] == str[j]){
            cnt++;
            j++;
        }
        if(cnt>1){
            res += str[i] + to_string(cnt);
        }else{
            res += str[i];
        }
        i=j;
    }
    return res;
}

int main(){
    string s;
    cin>>s;
    cout<<compress(s);
    return 0;
}
// aaaaabbbbbbbbbccccpqrstuv
