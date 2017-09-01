#include<bits/stdc++.h>

using namespace std;


int main(){
    int n, a[15];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    priority_queue<int, vector<int>, greater<int> > pq, pq1;

    for(int i=0; i<3; i++){
        pq.push(a[i]);
    }

    while(!pq.empty()){
        int tmp = pq.top();
        printf("%d ",pq.top());
        pq.pop();
        pq1.push(tmp);
    }
    printf("\n");
    while(!pq1.empty()){
        int t = pq1.top();
        pq1.pop();
        pq.push(t);
    }

    for(int i=3; i<n; i++){
        if(pq.top() < a[i]){
            pq.pop();
            pq.push(a[i]);
        }
        while(!pq.empty()){
            int tmp = pq.top();
            printf("%d ",pq.top());
            pq.pop();
            pq1.push(tmp);
        }
        printf("\n");
        while(!pq1.empty()){
            int t = pq1.top();
            pq1.pop();
            pq.push(t);
        }
    }
    return 0;
}
