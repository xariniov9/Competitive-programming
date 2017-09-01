#include<bits/stdc++.h>

char str[100000];



void buildTree()

int main(){
    int t=10;
    while(t--){
        scanf("%s",str);
        int n = strlen(str);
        buildTree(1, 0, n-1);

    }
}
