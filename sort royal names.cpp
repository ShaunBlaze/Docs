#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define bac(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef vector< ll > vi;
typedef vector<pair<ll,ll> > vpii;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define pi 3.1415926536
#define mod 1000000007
#define MAX 1000000
 
char a[]={'I','V','X','L','C','D','M'};
int b[]={1,5,10,50,100,500,1000};
unordered_map<char,int> m;
 
bool comp(string s, string t)
{
  for(int i=0;i<7;i++)
      m[a[i]]=b[i];
  vector<string> v[2]; 
  string temp;
  stringstream ss(s);
  while(getline(ss,temp,' '))
    v[0].pb(temp);
  stringstream ss1(t);
  while(getline(ss1,temp,' '))
    v[1].pb(temp);
  if(v[0][0]!=v[1][0])
    return (v[0][0]<v[1][0]);
  int n1=0,n2=0;
  string s1=v[0][1],s2=v[1][1];
  for(int i=0;i<s1.size();i++)
  {
     if(m[s1[i]]>=m[s1[i+1]])
       n1+=m[s1[i]];
     else
       n1-=m[s1[i]];
  }
  for(int i=0;i<s2.size();i++)
  {
     if(m[s2[i]]>=m[s2[i+1]])
       n2+=m[s2[i]];
     else
       n2-=+m[s2[i]];
  }
  //cout << n1 << " " << n2 << endl;
  return (n1<n2);
}
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
      int n,i;
      cin >> n;
      string s;
      vector<string> v(n);
      getline(cin,s,'\n');
      for(i=0;i<n;i++)
      {
        getline(cin,s,'\n');
        v[i]=s;
      }
      sort(v.begin(),v.end(),comp);
      for(i=0;i<n;i++)
      {
        cout << v[i] << endl;
      }
    } 
} 
