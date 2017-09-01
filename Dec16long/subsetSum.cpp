// A recursive solution for subset sum problem
#include <stdio.h>

#define MAX_N 30
#define MAX_SUM 20002

//int dp[MAX_N+5][MAX_SUM+5];

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
   // Base Cases
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;
   //if(dp[n][sum] != -1) return dp[n][sum];

   // If last element is greater than sum, then ignore it
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);

   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element   */
   return (isSubsetSum(set, n-1, sum) ||
                        isSubsetSum(set, n-1, sum-set[n-1]));
}

// Driver program to test above function
int main()
{
int t;
scanf("%d",&t);
while(t--){
    int set[25];
    int sum;
    int n;
    scanf("%d%d",&n,&sum);
    for(int i=0; i<n; i++)
        scanf("%d",&set[i]);
   /* for(int i=0; i<=n; i++){
        for(int j=0; j<MAX_SUM; j++){
            dp[i][j] = -1;
        }
    }*/
  if (isSubsetSum(set, n, sum) == true)
     printf("Yes\n");
  else
     printf("No\n");
  }
  return 0;
}
