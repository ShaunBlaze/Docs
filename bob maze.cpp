ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

ll n,m,x,y,cn;
vector<vector<ll>> g;
vector<pair<ll,ll>> coin;
vector<vector<ll>> dist; 
map<pair<ll,ll>,ll> um;

int main() {
    cin>>n>>m>>x>>y;
    g.assign(n,vector<ll>(m,0));
    coin.pb({0,0});
    um[{0,0}]=0;
    ll k=1;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>g[i][j];
            if(g[i][j]==2)
            { 
                coin.pb({i,j});
                um[{i,j}]=k++;     
            }
        }
    }
    coin.pb({x,y});
    um[{x,y}]=k;
    
    cn=coin.size();
    dist.assign(cn,vector<ll>(cn,INF));
    
    for(ll i=0;i<cn;i++)
    {
        dist[i][i]=0;
        queue<pair<pair<ll,ll>,ll>> q;
        q.push({{coin[i].fi,coin[i].se},0});
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vis[coin[i].fi][coin[i].se]=true;
        while(!q.empty())
        {
            auto p1=q.front();
            q.pop();
            auto p=p1.fi;
            int d=p1.se;
            for(int j=0;j<4;j++)
            {
                int nx=p.fi+dx[j];
                int ny=p.se+dy[j];
                if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny] || g[nx][ny]==1) continue;
                vis[nx][ny]=true;
                if(um.find({nx,ny})!=um.end())
                    dist[i][um[{nx,ny}]]=d+1;
                q.push({{nx,ny},d+1});
            }
        }
    }
    sort(coin.begin()+1,coin.begin()+cn-1);
    ll ans=INF;
    do{
        ll temp=0;
        for(ll i=0;i<cn-1;i++)
        {
            temp+=dist[i][i+1];
        }
        ans=min(ans,temp);
    }while(next_permutation(coin.begin()+1,coin.begin()+cn-1));
    cout<<ans<<endl;
    return 0;
}
