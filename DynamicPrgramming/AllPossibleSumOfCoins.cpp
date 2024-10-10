
#include<bits/stdc++.h>
using namespace std;
int memo[100][100];
int dp[100][100];
int allPossible(int coins[],int amount,int n)
{
    if(amount==0)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    else if(coins[n-1]<=amount)
    {
        int included=allPossible(coins,amount-coins[n-1],n);
        int excluded=allPossible(coins,amount,n-1);
        return included+excluded;
    }
    return allPossible(coins,amount,n-1);
}
int allPossibleUsingMemoization(int coins[],int amount,int n)
{
    if(amount==0)
    {
        return memo[n][amount]=1;
    }
    if(n==0)
    {
        return 0;
    }
    else if(coins[n-1]<=amount)
    {
        int included=allPossibleUsingMemoization(coins,amount-coins[n-1],n);
        int excluded=allPossibleUsingMemoization(coins,amount,n-1);
        return memo[n][amount]=included+excluded;

    }
    else
    {
        int excluded=allPossibleUsingMemoization(coins,amount,n-1);
        return memo[n][amount]=excluded;
    }

}
int main()
{
    int coins[]={1,3,4};
    int amount=9;
    int n=3;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            memo[i][j]=-1;
        }
    }
    cout<<allPossibleUsingMemoization(coins,amount,n);
}
