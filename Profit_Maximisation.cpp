#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
int dp[100][100];
int dfs(int s, int prev)
{
  if(s==v.size())
    return 0;
  if(prev!=-1 && dp[s][prev]!=-1)
    return dp[s][prev];
  int ans=0;
  for(int i=s;i<v.size();i++)
  {
    if(prev==-1 || v[i]%prev==0)
      ans=max(ans,v[i]+dfs(i+1,v[i]));
  }
  if(prev!=-1)
    dp[s][prev]=ans;
  return ans;
}
int main()
{
  int n,i;
  cin >> n;
  v.resize(n);
  for(i=0;i<n;i++)
    cin >> v[i];
  memset(dp,-1,sizeof(dp));
  cout << dfs(0,-1);
}
