    int dist[10000];
    vector<vector<int>> graph;
    int downPath(int s)
    {
        if(graph[s].size()==0)
            return dist[s]=0;
        int ans =INT_MAX ;
        for(int i=0; i<graph[s].size(); i++)
        {
            ans = min(ans, 1+downPath(graph[s][i]));
        }
        return dist[s]=ans;
    }
    void dfs(int s)
    {
        for(int i=0; i<graph[s].size(); i++)
        {
            int v = graph[s][i];
            dist[v] = min(dist[v], dist[s]+1);
        }
        return ;
    }
    int main()
    {
        fast
        int n,m;
        cin>>n>>m;
        graph.assign(n,vector<int>(0));
        for(int i=0; i<m; i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
        }
        downPath(0);
        dfs(0);
        for(int i=0; i<n; i++)
            cout<<dist[i]<<" ";
        return 0;   
    }
