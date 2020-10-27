#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool vis[100]={0};
int edges,nodes;

void dfs(int s)
{
  vis[s]=1;
  edges+=adj[s].size();
  nodes++;
  for(auto x: adj[s])
  {
    if(vis[x]==0)
      dfs(x);
  }
}

int main()
{
  int n,m,x,y,cnt=0,extra=0;
  cin >> n;
  cin >> m;
  for(int i=0;i<m;i++)
  {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for(int i=1;i<=n;i++)
  {
    edges=0;
    nodes=0;
    if(vis[i]==0)
    {
      cnt++;
      dfs(i);
      edges=edges/2;
      extra+=(edges-nodes+1);
    }
  }
  if(extra>=cnt-1)
    cout << cnt-1;
  else
    cout << -1;
}
