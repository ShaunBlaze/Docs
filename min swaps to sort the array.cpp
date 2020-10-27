        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<ll> b=v;
        sort(b.begin(),b.end(),greater<ll>());
        vector<ll> m(20006,0);
        for(auto i=0;i<n;i++) m[b[i]]=i; 
        ll ans=0;
        
        for(ll i=0;i<n;i++)
        {
            for(ll j=m[v[i]];j!=i;j=m[v[i]])
            {
                swap(v[i],v[j]);
                ans++;
            }
        }
        cout<<ans<<endl;
