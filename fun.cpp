#include<iostream>
using namespace std;

int main(){
    int N = 5;
    //for (int i=0 ; i<25 ; i++)
       // for (int i=0 ; i<25 ; i++)
        //{
            for (int i=1; i<=N*N; i++)
            {
                int j=i/N,k=i%N+1;
                if(k<=j)
                    cout<<k<<" ";
                else if(k-j<j)
                    cout<<k-j<<endl;
            }
            //cout<<endl;
        //}
        return 0;
}
