#include<bits/stdc++.h>

using namespace std;

class comp {
public:
        bool operator() (const int & a, const int & b){

        return a>b;
    }
};

int main(){
    set<int, comp> s;
    for(int i=10; i>=1; i--)
        s.insert(i);
    while(s.size() != 0){
        printf("%d ",*s.begin());
        s.erase(s.begin());
    }
    printf("\n");
}
