#include<bits/stdc++.h>
using namespace std;
int minCoins(int coins[],int sum,int n)
{
  if (sum == 0) {
        return 0;
    }
    if (n == 0) {
        return INT_MAX;
    }
    if (coins[n - 1] <= sum) {
        int include = minCoins(coins, sum - coins[n - 1], n);
        int exclude = minCoins(coins, sum, n - 1);
        if (include != INT_MAX) {
            return min(1 + include, exclude);
        } else {
            return exclude;
        }
    } else {
        return minCoins(coins, sum, n - 1);
    }

}
int main()
{

    int coins[] = {25, 10, 5};
    int sum = 30;
    int n=3;
    cout<<minCoins(coins,sum,n);

    }
