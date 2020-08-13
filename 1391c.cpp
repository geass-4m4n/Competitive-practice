#include <bits/stdc++.h>
using namespace std;
 
//remember-> largest 2d memory that can be allocated is dp[5100][5100];
/*for (auto x: mymap) {
  cout << x.first << endl;
}
map<char,ll>::iterator it=mymap.begin();
*/
 
/*x=x%2;
    ll res=1;
    while(res>0)
    {
        if(y%2==1)
           res=(res*n)%pow;
           y/=2;
           x=(x*x)%pow;
    }
     return r*/
 
#define ll long long int
#define ull unsigned long long int
 
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define str string
#define pq priority_queue
#define vi vector< ll >
#define vii vector< vi >
#define viii vector< vii >
#define pii pair< ll, ll >
#define vpii vector< pii >
#define mii map< ll , ll >
#define len length()
#define pb push_back
#define mp make_pair3
#define ff first
#define ss second
#define nl cout <<  endl
#define all(ar) ar.begin(), ar.end()
#define ini(X,Y) ll X; X=Y
#define inx(X) ll X; cin >> X
#define inxy(X, Y) ll X, Y; cin >> X >> Y
#define iter(arr) for (ll i=0; i<arr.size(); i++)
#define riter(arr) for (ll i=arr.size()-1; i>=0; i--)
#define itn(n) for (ll i=0; i<n; i++)
#define ritn(n) for (ll i=n-1; i>=0; i--)
#define cont continue
#define brk break
#define sortt(arr) sort(arr.begin(),arr.end())
#define rsortt(arr) sort(arr.rbegin(),arr.rend())
 
#define tcase ll t;cin>>t;while(t--)
const ll INF = 0x3f3f3f3f;
const double eps = 1e-8;
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
#define pow 1000000007
#define modd 490019
#define basss ll n;cin>>n;ll arr[n];for(ll i=0;i<n;i++)cin>>arr[i]
 
/*x=x%2;
    ll res=1;
    while(res>0)
    {
        if(y%2==1)
           res=(res*n)%pow;
           y/=2;
           x=(x*x)%pow;
    }
     return r*/
#define siz 200005

int max_ele(vector<int>v)
{
    int m=v[0];
    for(int i=0;i<10;i++)
    m=max(m,v[i]);

    return m;
}

int main()
{

  fast;
  ll n;
  cin>>n;
  ull f=1;
  for(ll i=1;i<=n;i++)
    f= (f*i)%pow;
  ull g=1;
  for(ll i=1;i<n;i++)
  g=(g*2)%pow;

  ull ans =(f-g+pow)%pow;
  cout<<ans<<endl;
}
