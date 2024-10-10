#include<iostream>
using namespace std;
#include<vector>
KnapsackRecursion(int weight[],int price[],int W,int n)
{

    if(n==0||W==0)
    {
        return 0;
    }
    else if(weight[n-1]<=W)
    {
        int include=price[n-1]+KnapsackRecursion(weight,price,W-weight[n-1],n-1);
        int exclude=KnapsackRecursion(weight,price,W,n-1);
        return max(include,exclude);
    }
    else {
        return KnapsackRecursion(weight,price,W,n-1);
    }
}
int dp[1000][1000];
//Top Down Approach
int knapsackMemoization(int weight[],int profit[],int W,int n)
{
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    else if(weight[n-1]<=W)
    {
        int include=profit[n-1]+knapsackMemoization(weight,profit,W-weight[n-1],n-1);
        int exclude=knapsackMemoization(weight,profit,W-weight[n-1],n-1);
        return dp[n][W]=max(include,exclude);

    }
    else
    {
        int exclude=knapsackMemoization(weight,profit,W-weight[n-1],n-1);
        return dp[n][W]=exclude;
    }

}
//using tabulation method
int tabulation(int weight[],int profit[],int W,int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {

            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(weight[i-1]<=W)
            {
                dp[i][j]=max((profit[i-1]+dp[i-1][j-weight[i-1]]),dp[i-1][j]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];


}
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int> > K(n + 1, vector<int>(W + 1));


    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1]
                                  + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
int main()
{
   int weight[]={3,5,2,7,4};
   int price[]={150,200,100,300,180};
   int W=10;
   int n=sizeof(weight)/sizeof(weight[0]);
   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=W;j++)
       {
           if(i==0||j==0)
           {
               dp[i][j]=0;
           }
           else
           {
               dp[i][j]=-1;
           }
       }
   }
   cout<<tabulation(weight,price,W,n);
      cout<<endl;
         cout<<KnapsackRecursion(weight,price,W,n);
      cout<<endl;
      for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=W;j++)
       {
            cout<<dp[i][j]<<" ";
       }
       cout<<endl;
   }
}
