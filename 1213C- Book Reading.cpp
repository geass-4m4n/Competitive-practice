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
int main()
{
    fast;
    tcase{

        ull m, n;
        cin>>n>>m;

        if(m>n||m%10==0){
            cout<<0<<endl;
        continue;
        }

        ull num= n/m;
        vector<vector<ull> > arr{ {0 }, 
                               { 1, 2, 3,4,5,6,7,8,9,0}, 
                               { 2,4,6,8,0 } ,
                               { 3,6,9,2,5,8,1,4,7,0 },
                               { 4,8,2,6,0},
                               {5,0},
                               {6,2,8,4,0},
                                {7,4,1,8,5,2,9,6,3,0},
                                {8,6,4,2,0},
                                {9,8,7,6,5,4,3,2,1,0} };

        ull key=m%10;
        vector<ull>ansk=arr[key];
        ull sum=0;
        ull keys=ansk.size();

        ull nm = num/keys;
        ull rem= num%keys;

        for(int i=0;i<ansk.size();i++)
        sum=sum+ansk[i];

        ull ans= sum*nm;
        ull r=0;
        for(int i=0;i<rem;i++)
        r=r+ansk[i];

        ans= ans+r;
        cout<<ans<<endl;



        
    }
 
}
