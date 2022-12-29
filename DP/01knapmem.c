#include<stdio.h>
int dp[4][51];
int max(int a, int b) {
   if(a>b){
      return a;
   } else {
      return b;
   }
}

int knapsackmem(int W,int wt[],int val[],int n){
if(n==0 || W==0){

return 0;
}
int ans=0;
    if(wt[n-1]<=W){
         dp[n][W]=max(val[n-1]+knapsackmem(W-wt[n-1],wt,val,n-1),knapsackmem(W,wt,val,n-1));

    }else{
        dp[n][W]=knapsackmem(W,wt,val,n-1);
    }
    return dp[n][W];
    }
int main() {

   int val[] = {60, 100, 120};
   int wt[] = {10, 20, 30};
   int W = 50;
   int n = sizeof(val)/sizeof(val[0]);
   for(int i=0;i<4;i++){
    for(int j=0;j<51;j++){
        dp[i][j]=-1;
    }
   }
   
   printf("The solution is aaa: %d", knapsackmem(W, wt, val, 3));
   
//    printf("The solution is : %d", knapsack(W, wt, val, n));
   return 0;
}