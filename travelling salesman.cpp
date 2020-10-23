#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dfs(int city, int mask, vector<vector<int>> &v, vector<vector<int>> &dp, int &p)
{
  if(mask==p)
    return v[city][0];
  if(dp[city][mask]!=-1)
    return dp[city][mask];
  int ans=INT_MAX;
  for(int i=0;i<v.size();i++)
  {
    if(mask & (1<<i))
      continue;
    ans=min(ans,v[city][i]+dfs(i,mask^(1<<i),v,dp,p));
  }
  dp[city][mask]=ans;
  return ans;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n,i,j=0,p=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
      p=p+pow(2,i);
    }
    vector<vector<int>> v(n,vector<int>(n));
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        cin >> v[i][j];
    }
    vector<vector<int>> dp(n,vector<int>(p+1,-1));
    cout << dfs(0,1,v,dp,p) << endl;
  } 
}
