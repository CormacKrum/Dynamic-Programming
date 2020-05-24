#include<bits/stdc++.h>
using namespace std;
int lcsDP(string s1,string s2)
{
    int x=s1.length();
    int y=s2.length();
    int **dp=new int*[x+1];
    for(int i=0;i<=x;i++)
    {
        dp[i]=new int[y+1];
    }
    for(int i=0;i<=x;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=y;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[x][y];
}
int main()
{
    string str,str2;
    cout<<"Enter the value of string 1:\n";
    cin>>str;
    cout<<"Enter the value of string 2:\n";
    cin>>str2;
    cout<<"Length of Longest Common Sequence in both string is : "<<lcsDP(str,str2)<<endl;
}
