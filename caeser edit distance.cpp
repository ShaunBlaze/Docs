#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int dfs(string &s, string &t, int n, int m)
{
  if(n==0 && m==0)
    return 0;
  if(n==0)
    return m;
  if(m==0)
    return n;
  if(dp[n][m]!=-1)
    return dp[n][m];
  int ans;
  if(s[n-1]==t[m-1])
    ans=dfs(s,t,n-1,m-1);
  else
  {
    ans=min(1+dfs(s,t,n-1,m),1+dfs(s,t,n,m-1));
  }
  return dp[n][m]=ans;
}

int main()
{
  string s,t;
  cin >> s >> t;
  int i,j,n=s.size(),m=t.size();
  int mini=INT_MAX;
  for(i=0;i<26;i++)
  {
    string temp=s;
    for(j=0;j<n;j++)
    {
      int x=temp[j]-'a';
      temp[j]=(x+i)%26+'a';
    }
    //cout << temp << endl;
    memset(dp,-1,sizeof(dp));
    mini=min(mini,dfs(temp,t,n,m));
  }
  cout << mini;
}
