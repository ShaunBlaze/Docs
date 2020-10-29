#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int dfs(int pos, int k, vector<int> &v)
{
  if(pos==v.size() && k==0)
    return 0;
  if(k<0)
    return INT_MIN;
  if(dp[pos][k]!=-1)
    return dp[pos][k];
  int sum=0,cnt=0,ans=INT_MIN;
  for(int i=pos;i<v.size();i++)
  {
    sum+=v[i];
    cnt++;
    int temp=dfs(i+1,k-1,v);
    if(temp==INT_MIN)
      continue;
    ans=max(ans,sum/cnt+temp);
  }
  return dp[pos][k]=ans;
}

int main()
{
  int n,m,x,y,k;
  cin >> n >> k;
  vector<int> v(n);
  for(int i=0;i<n;i++)
  {
    cin >> v[i];
  }
  memset(dp,-1,sizeof(dp));
  cout << dfs(0,k,v);
}
