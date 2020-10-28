    int main() {
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n),bur(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];

        for(ll i=0;i<n;i++)
            cin>>bur[i];
        vector<pair<ll,ll>> zip(n);
        for(ll i=0;i<n;i++)
        {
            zip[i]=mp(arr[i],arr[i]+bur[i]-1);
        }
        sort(zip.begin(),zip.end());
        vector<ll> server(k,0);
        vector<ll> ans(k,0);
        ll j=0;
        // 6 4 6
        // 1 2 3 4 5
        // 6 4 6 7 8      
        for(ll i=0;i<n;i++)
        {
            ll cnt=0;
            while(server[j]>zip[i].fi && cnt!=k)
            {
                cnt++;
                j= (j+1)%k;
            }
            if(cnt!=k)
            {
                server[j]=zip[i].se;
                ans[j]++;
                j= (j+1)%k;
                
            }
        }
        ll m=*max_element(ans.begin(),ans.end());
        vector<ll> ans2;
        for(int i=0;i<k;i++) if(ans[i]==m) ans2.push_back(i+1);
        for(auto i:ans2) cout<<i<<endl;
    }
    return 0;
}
