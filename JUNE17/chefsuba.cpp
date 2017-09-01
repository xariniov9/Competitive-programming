
#include<bits/stdc++.h>

using namespace std;

int a[2*100005];
int sum[2*100005] = {0};
int mx[2*100005];
char Q[100005];

int main(){
    int n, k, p;
    scanf("%d%d%d",&n,&k,&p);
    k = k>n ? n:k;
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(int i=n; i<2*n; i++)
        a[i] = a[i-n];

    int it=0;
    for(int i=0; i<k; i++){
        sum[it] += a[i];
    }
    it++;
    for(int i=k; i<2*n; i++){
        sum[it] = sum[it-1] - a[i-k] + a[i];
        it++;
    }
    scanf("%s",Q);
    int ws = n-k+1;

    deque<int> dq;
    int i;
    for(i=0; i<ws; i++){
        while(!dq.empty() && sum[i] >= sum[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    int itr=0;
    for(; i<it; i++){
        mx[itr++] = sum[dq.front()];
        while(!dq.empty() && dq.front() <= i-ws)
            dq.pop_front();
        while(!dq.empty() && sum[i] >= sum[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    mx[itr++] = sum[dq.front()];

    /*for(int i=0; i<itr; i++)
        printf("%d ",mx[i]);
    printf("\n");*/
    itr--;
    int ITR = itr;
    for(int i=0; i<p; i++){
        if(itr == 0)
            itr = ITR;
        if(Q[i] == '!')
            itr--;
        else
            printf("%d\n",mx[itr]);
    }

    return 0;
}
