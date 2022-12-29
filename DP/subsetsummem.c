#include <stdio.h>

int dp[7][10];
int isSubsetSum(int arr[], int n, int sum)
{

	if (sum == 0)
		return 1;
	if (n == 0 )
		return 0;
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(arr[n-1]<=sum){
 dp[n][sum]=(isSubsetSum(arr, n - 1, sum) ||
		isSubsetSum(arr, n - 1, sum - arr[n - 1]));
    }else if(arr[n - 1] > sum){

		 dp[n][sum]= isSubsetSum(arr, n - 1, sum);
	}

	return dp[n][sum];


	
}

int main()
{
	int arr[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 1;
	int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            dp[i][j]=-1
			;
        }
    }
	if (isSubsetSum(arr, n, sum) == 1)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	return 0;
}
