#include <stdio.h>
#include <stdbool.h>
bool dp[7][10];
bool subset(int arr[], int n, int sum) {

  bool dp[n + 1][sum + 1];
  for (int i = 0; i <= n; i++)
    dp[i][0] = true;

  for (int i = 1; i <= sum; i++)
    dp[0][i] = false;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (j < arr[i - 1])
        dp[i][j] = dp[i - 1][j];
      if (j >= arr[i - 1])
        dp[i][j] = dp[i - 1][j] ||
        dp[i - 1][j - arr[i - 1]];
    }
  }
  return dp[n][sum];
}

int main()
{
	int arr[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(arr) / sizeof(arr[0]);
  
	if (subset(arr, n, sum) == 1)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	return 0;
}
