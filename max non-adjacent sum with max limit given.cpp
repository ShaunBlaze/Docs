    int n;
    int dp[1005][100][2];
    int solve(int arr[], int i, int w, bool flag)
    {
        if(w<0) return INT_MIN;
        if(w==0 || i>=n)
            return 0;
        if(dp[i][w][flag]!=-1) return dp[i][w][flag];
        int ans=0;
        ans = max(ans , solve(arr, i+1, w, !flag));
        if(!flag)
        {
            ans = max(ans , arr[i] + solve(arr, i+1, w-arr[i], !flag));
        }
        return dp[i][w][flag] = ans;
    }
    int main()
    {
        cin>>n;
        int arr[n];
        int num;
        for(int i=0; i<n; i++)cin>>arr[i];
        cin>>num;
        memset(dp,-1,sizeof(dp));
        cout<<solve(arr,0,num,false);
        return 0;   
    }
