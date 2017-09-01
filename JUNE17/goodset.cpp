#include<bits/stdc++.h>

using namespace std;

int arr[1000];

void pre(){
    arr[0] = 1;
    for(int j=1; j<=99; j++){
        for(int i=0; i<j; i++){
            for(int k=arr[j-1] + 1; k<=500; k++){
                int * itr = lower_bound(arr, arr+j, k-arr[i]);
                if(*itr != k-arr[i] && k-arr[i] != arr[i])
                {
                    arr[j] = k;
                    break;
                }
            }
        }
    }
}

int main(){
    int t;
    pre();
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}

//9599893036
