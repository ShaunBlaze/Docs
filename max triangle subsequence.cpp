#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,j=2;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++)
    cin >> a[i];
  sort(a,a+n);
  int ans=0;
  for(int i=0;i<n-2;i++)
  {
    j=max(j,i+2);
    while(j<n && a[i]+a[i+1]>a[j])
    {
      ans=max(ans,j-i+1);
      j++;
    }
  }
  cout << ans;
}
