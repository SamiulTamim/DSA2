#include<bits/stdc++.h>
using namespace std;
int minCoins(int coins[],int amount,int n)
{
    if(amount==0)
    {
        return 0;
    }
    if(n==0)
    {
        return INT_MAX;
    }
    else if(coins[n-1]<=amount)
    {
         int included=minCoins(coins,amount-coins[n-1],n);
         if(included!=INT_MAX)
         {
             included=included+1;
         }
         int excluded=minCoins(coins,amount,n-1);
         return min(included,excluded);
    }
    else return minCoins(coins,amount,n-1);


}
int main()
{
  int coins[]={1,3,4};
    int amount=6;
    int n=3;
    cout<<minCoins(coins,amount,n);
}
