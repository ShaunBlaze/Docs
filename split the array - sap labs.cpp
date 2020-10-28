#include <bits/stdc++.h>
using namespace std;

int dp[100];
int dfs(int pos, vector<int> &v)
{
  if(pos==v.size())
    return 0;
  if(dp[pos]!=-1)
    return dp[pos];
  int ans=INT_MAX-1;
  for(int i=pos;i<v.size();i++)
  {
    if(__gcd(v[i],v[pos])==1)
      continue;
    ans=min(ans,1+dfs(i+1,v));
  }
  return dp[pos]=ans;
}

int main()
{
  int n,m,x,y;
  cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++)
  {
    cin >> v[i];
  }
  memset(dp,-1,sizeof(dp));
  cout << dfs(0,v);
}
