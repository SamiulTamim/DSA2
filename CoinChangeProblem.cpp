#include<iostream>
using namespace std;
int dp[1000][1000];
int minimumCoinUsingRecursion(int coins[],int amount,int n)
{
    if(amount==0)
    {
        return 0;
    }
    if(n==0)return INT_MAX;
    if(coins[n-1]<=amount)
    {
        int included=minimumCoinUsingRecursion(coins,amount-coins[n-1],n);
          if (included != INT_MAX) {
            included += 1; // Add 1 coin used in this case
        }
        int excluded=minimumCoinUsingRecursion(coins,amount,n-1);
        return min(included,excluded);

    }
    else
    {
        return minimumCoinUsingRecursion(coins,amount,n-1);
    }

}
int usingMemoization(int coins[],int amount,int n)
{
    if(amount==0)
    {
        return 0;//I have reached my final Destination or I don't want any money
    }
    if(n==0)
    {
        return INT_MAX;
    }
    if(coins[n-1]<=amount)
    {
        int included=usingMemoization(coins,amount-coins[n-1],n);
        if(included!=INT_MAX)
        {
            included=1+included;


        }
        int excluded=usingMemoization(coins,amount,n-1);
        if(included!=INT_MAX){
        dp[n][amount]=min(included,excluded);
        return dp[n][amount];
        }
    }
    else{
        return dp[n][amount]=usingMemoization(coins,amount,n-1);
    }

    return dp[n][amount];
}
int usingTabular(int coins[],int amount,int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(coins[i-1]<=j)
            {
                 int included=dp[i-1][j-coins[i-1]];
                 int excluded=dp[i-1][j];
                 if(included!=INT_MAX){
                 dp[i][j]=min(1+included,excluded);

                 }

            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][amount];


}

int main()
{
    int coins[]={1,3,4};
    int amount=32;
    int n=3;
    int result = usingTabular(coins, amount, n);
        for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            cout<< dp[i][j]<<" ";
        }
        cout<<endl;

    }
     if (result == INT_MAX) {
       cout << "It's not possible to form the amount with the given coins." << std::endl;
    } else {
       cout << "Minimum number of coins required: " << result << std::endl;
    }
}
