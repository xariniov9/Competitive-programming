#include<bits/stdc++.h>

#define ll long long int
#define MX 101
inline ll power(int base,int n){
  ll ans=1;
  while(n){
    if(n&1==1) ans*=base;
    base*=base;
    n=(n>>1);
  }
  return ans;
}


int main(){
  int i,j,k,n,l;
  int t[MX]={0};
  for(i=1;i<MX;i++) t[i]=i*i*i;
  for(n=2;n<MX;n++){
    for(i=2;t[i]<t[n];i++){
      for(j=i;t[j]<t[n]-t[i];j++){
        for(k=j;t[k]<=t[n]-t[i]-t[j];k++){
            if(t[k]==t[n]-t[i]-t[j]) printf("Cube = %d, Triple = (%d,%d,%d)\n",n,i,j,k);
        }
      }
    }
  }
  return 0;
}

