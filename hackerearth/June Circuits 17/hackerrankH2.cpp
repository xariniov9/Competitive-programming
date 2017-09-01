
#include<bits/stdc++.h>

using namespace std;


bool solve(string s){
    /*if(idx == n && started != 0){
        return (num%8) == 0;
    }
    if(num % 8 == 0 && started != 0)
        return true;

    bool smaller = solve(idx+1, num, started);
    if(smaller)
        return true;
    int num1 = num%100;
    int n1 = num1 * 10 + num[idx] - '0';
    smaller = solve(idx+1, n1, 1);

    if(num)*/
    int n= s.size();
    if(n==1){
        return (s[0] - '0') % 8 == 0;
    }
    if(n==2){
        int n1 = (s[0] - '0')*10 + s[1] - '0';
        int n2 = (s[1] - '0')*10 + s[0] - '0';
        return (n1%8 == 0 ) || n2%8 == 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(i != j && j!=k && i != k){
                    int num = (s[i] - '0')*100 + (s[j] - '0')*10 + s[k] - '0';
                    if(num % 8 == 0)
                        return true;
                }
            }
        }
    }
    return false;
}

vector<string> checkDivisibility(vector<string> arr){
    vector<string> op;
    for(int i=0; i<arr.size(); i++){
        if(solve(arr[i]))
            op.push_back("YES");
        else
            op.push_back("NO");
    }
    return op;
}

int main(){
    int n;
    string s;
    vector<string> inp;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        cin>>s;
        inp.push_back(s);
    }
    vector<string> res = checkDivisibility(inp);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<endl;
    return 0;
}
