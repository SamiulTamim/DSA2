#include<iostream>
using namespace std;
int LcsUsingRecursion(string s1,string s2,int i,int j)
{
    if(s1[i]=='\0'||s2[j]=='\0') return 0;
    else if(s1[i]==s2[j]) return(1+LcsUsingRecursion(s1,s2,i+1,j+1));
    else return max(LcsUsingRecursion(s1,s2,i+1,j),LcsUsingRecursion(s1,s2,i+1,j));
}

int main()
{
    string s1="bd";
    string s2="abcd";
    cout<<LcsUsingRecursion(s1,s2,0,0);

}
