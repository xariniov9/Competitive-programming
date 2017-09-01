#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int arr[1002][1002];
bool prime[100002];
int path[1002][1002];
int dp[1002][1002];
int n,m;
void sieve()
{
    memset(prime,true,sizeof(prime));
    for(int i=2;i*i<=100000;i++)
    {
        if(prime[i]==true)
        {
            for(int k=2*i;k<=100000;k+=i)
             prime[k]=false;
        }
    }
}

int no_of_ways(int xc,int yc)
{
    if(xc==n-1 && yc==m-1 ) return dp[xc][yc] = 1;
    if(xc>=n || yc>=m) return 0;
    if(path[xc][yc]==1) return 0;

    if(dp[xc][yc]!=-1) return dp[xc][yc];
    long long ans=( no_of_ways(xc+1,yc)%mod + no_of_ways(xc,yc+1)%mod + no_of_ways(xc+1,yc+1)%mod )%mod;
    dp[xc][yc]=ans;
    return ans;
}

void order_print(int i,int j)
{
   if(i>=n || j>=m) return;
   if(i==n-1 && j==m-1)
    {
        cout<<i+1<<" "<<j+1<<"\n";
        return;
    }

     cout<<i+1<<" "<<j+1<<"\n";
     if(dp[i+1][j+1]>0) order_print(i+1,j+1);
     else if(dp[i+1][j]>0) order_print(i+1,j);
     else  order_print(i,j+1);
}


int main() {
ios_base::sync_with_stdio(0);

 cin>>n>>m;

 sieve();

 for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          cin>>arr[i][j];
          if(prime[arr[i][j]]==true)
            path[i][j]=0;
          else path[i][j]=1;

          dp[i][j]=-1;
      }
  }

   long long res=no_of_ways(0,0);
   cout<<res<<"\n";

   if(res==0) cout<<"0"<<"\n";
   else {
       order_print(0,0);
      // cout<<n<<" "<<m<<"\n";
   }


	return 0;
}
