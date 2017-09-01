// problem link : https://www.codechef.com/problems/XRQRS

// will solve it with persistent tries

#include<bits/stdc++.h>

using namespace std;


int arr[512345] = {0};

int main(){
    int m, n =0;
    scanf("%d",&m);
    while(m--){
        int type, x;
        scanf("%d",&type);
        if(type == 0){
            scanf("%d",&x);
            arr[n] = x;
            n++;

            updateBIT(...);
            InsertTrie(...);
        }


    }



}
