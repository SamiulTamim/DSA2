#include<iostream>
using namespace std;
int dp[1000][1000];
int tab[1000][1000];
int LCS(string str1,string str2,int i,int j)
{

if(str1[i]=='\0'||str2[j]=='\0')
{
    return 0;
}
else if(dp[i][j]!=-1)
{
    return dp[i][j];
}
else if(str1[i]==str2[j])
{
    return dp[i][j]=1+LCS(str1,str2,i+1,j+1);
}
else {
       int first=LCS(str1,str2,i+1,j);
       int second=LCS(str1,str2,i,j+1);
       return dp[i][j]=max(first,second);

}
}
int usingDp(string s1,string s2,int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
              dp[i][j]=0;

            }
            else if(s1[i]==s2[j])
            {
                dp[i][j]=1+dp[i-1][j-1];

            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string str1 = "bd", str2 = "abcd";


    cout<<usingDp(str1,str2,str1.size(),str2.size());
}
