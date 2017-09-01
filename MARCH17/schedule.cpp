#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

int a[1000005];
char str[1000005];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        priority_queue<int> pq;
        int n, k, curr=0, cd;
        scanf("%d%d",&n,&k);
        scanf("%s",str);
        for(int i=1; i<=n; i++){
            if(str[i-1] == '1')
                a[i]=1;
            else
                a[i] = 0;
        }
        a[0] = a[1];
        a[n+1] = -1;
        for(int i=1; i<=n+1; i++){
            if(a[i] == a[i-1]){
                curr++;
            } else{
               // printf("~ %d\n", curr);
                pq.push(curr);
                curr = 1;
            }
        }
        for(int i=0; i<k; i++){
            if(pq.top() <= 2)
                break;
            int top = pq.top();
            pq.pop();
            if(top & 1){
                pq.push(top/2);
                pq.push(top/2);
            } else{
                pq.push(top/2);
                pq.push(top/2-1);
            }
        }
        printf("%d\n",pq.top());
    }
    return 0;
}
