
// A naive C/C++ based recursive implementation of LIS problem
#include<stdio.h>
#include<stdlib.h>

// Recursive implementation for calculating the LIS

int N = 100;

int dp[100][100];

int _lis(int arr[], int n, int *max_lis_length)
{
    // Base case
    if (n == 1)
        return 1;

    //add this
    if(dp[n][*max_lis_length] != -1)
        return dp[n][*max_lis_length];
    int current_lis_length = 1;
    for (int i=0; i<n-1; i++)
    {
        // Recursively calculate the length of the LIS
        // ending at arr[i]
        int subproblem_lis_length = _lis(arr, i, max_lis_length);

        // Check if appending arr[n-1] to the LIS
        // ending at arr[i] gives us an LIS ending at
        // arr[n-1] which is longer than the previously
        // calculated LIS ending at arr[n-1]
        if (arr[i] < arr[n-1] &&
            current_lis_length < (1+subproblem_lis_length))
            current_lis_length = 1+subproblem_lis_length;
    }

    // Check if currently calculated LIS ending at
    // arr[n-1] is longer than the previously calculated
    // LIS and update max_lis_length accordingly
    if (*max_lis_length < current_lis_length)
        *max_lis_length = current_lis_length;

    return (dp[n][*max_lis_length] = current_lis_length);
}

// The wrapper function for _lis()
int lis(int arr[], int n)
{
    int max_lis_length = 1; // stores the final LIS

    // max_lis_length is passed as a reference below
    // so that it can maintain its value
    // between the recursive calls
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = -1;
    _lis( arr, n, &max_lis_length );

    return max_lis_length;
}

// Driver program to test the functions above
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n", lis( arr, n ));
    return 0;
}
