    int main()
    {
            fast
       int n; cin>>n;
        int pos[n]; int h[n];
        for(int i=0; i<n; i++)
            cin>>pos[i];
        for(int i=0; i<n; i++)cin>>h[i];
        int ans = 0;
        for(int i=1; i<n; i++)
        {
            if((pos[i]-pos[i-1]-1)<=abs(h[i]-h[i-1]))
            {
                ans = max(ans , min(h[i],h[i-1])+(pos[i]-pos[i-1]-1));
            }
            else
            {
                 int mid = (pos[i] - pos[i-1])/2;
            if((pos[i] - pos[i-1])%2==0)
            {
                ans = max(ans , min(h[i-1],h[i])+mid);
            }
            else
                ans = max(ans , min(h[i-1],h[i])+mid+1);
                
            }
           
                
        }
     cout<<ans;
