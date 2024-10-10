#include<bits/stdc++.h>
using namespace std;
int memo[1000][1000];
int knapSack(int profit[],int weight[],int n,int s)
{

    if(n==0||s==0)
    {
        return 0;
    }
    else if(weight[n-1]<=s)
    {
        int include=profit[n-1]+knapSack(profit,weight,n,s-weight[n-1]);
        int exclude=knapSack(profit,weight,n-1,s);
        return max(include,exclude);
    }
    else {
        return knapSack(profit,weight,n-1,s);
    }
}
int knapSack2(int profit[],int weight[],int n,int s)
{

    if(n==0||s==0)
    {
        return 0;
    }
    else if(memo[n][s]!=-1)
    {

        return memo[n][s];
    }
    else if(weight[n-1]<=s)
    {
        int include=profit[n-1]+knapSack2(profit,weight,n,s-weight[n-1]);
        int exclude=knapSack2(profit,weight,n-1,s);
        return memo[n][s]=max(include,exclude);
    }
    else {
        return memo[n][s]=knapSack2(profit,weight,n-1,s);
    }


}
int main()
{
    int profit[]={1,2,3};
    int weight[]={4,5,1};
    int n=sizeof(profit)/sizeof(profit[0]);
    int sackSize=3;
    cout<<knapSack(profit,weight,n,sackSize)<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sackSize;j++)
        {
            memo[i][j]=-1;
        }
    }
    cout<<knapSack2(profit,weight,n,sackSize);
}
