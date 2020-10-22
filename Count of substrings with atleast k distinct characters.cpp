#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*vector<int> v;
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
}*/
int solve(int k, string s)
{
  int i,ans=0,j=0;
  unordered_map<char,int> m;
  for(i=0;i<s.size();i++)
  {
    m[s[i]]++;
    while(m.size()>=k)
    {
      ans+=(s.size()-i);
      m[s[j]]--;
      if(m[s[j]]==0)
        m.erase(s[j]);
      j++;
    }
  }
  return ans;
}
int main()
{
  int n,i,j=0;
  cin >> n;
  string s;
  cin >> s;
  for(i=1;i<=26;i++)
    cout << solve(i,s) << " ";
}
