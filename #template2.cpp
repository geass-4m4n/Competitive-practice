/*
  AUTHOR:SOURABH
  CREATED:26:01:19
*/
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define W while
#define fn(i,x) for(i=0;i<x;i++)
#define fs(i,s,x) for(i=s;i<x;i++)
#define fr(i,x) for(i=x;i>=0;i--)
#define fit(it,s) for(it=s.begin();it!=s.end();it++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define mod 1000000007
#define MAX 100005
#define M 32

using namespace std;

vector<pair<ll,pll> > p(200001);
vll a(200001);
vll si(200001);

/*
///------------------------------------------------>MODEX<-------------------------------------------------------------///
ll modex(ll x,ll y)
{
    x=x%mod;
    ll r=1;
    while(y>0)
    {
        if(y%2==1)
            r=(r*x)%mod;
        y/=2;
        x=(x*x)%mod;
    }
    return r;
}
///*********************************************************************************************************************///

/*
///-------------------------------------------->SEGMENTED TREE<---------------------------------------------------------///
void build(ll node,ll s,ll e)
{
    if(s==e)
    {
        tree[node]=a[s];
    }
    else
    {
        ll mid=(s+e)/2;
        build(2*node,s,mid);
        build(2*node+1,mid+1,e);

        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
void update(ll node,ll s,ll e,ll idx,ll val)
{
    if(s==e)
    {
        a[idx]=val;
        tree[node]=val;
    }
    else
    {
        ll mid=(s+e)/2;
        if(s<=idx && idx<=mid)
        {
            update(2*node,s,mid,idx,val);
        }
        else
        {
            update(2*node+1,mid+1,e,idx,val);
        }

        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
ll query(ll node,ll s,ll e,ll l,ll r)
{
    if(r<s || e<l)
    {
        return 0;
    }
    if(l<=s && e<=r)
    {
        return tree[node];
    }
    ll mid=(s+e)/2;
    ll p1=query(2*node,s,mid,l,r);
    ll p2=query(2*node+1,mid+1,e,l,r);
    return min(p1,p2);
}
void rangeupdate(ll node,ll s,ll e,ll l,ll r,ll val)
{
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(s!=e)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(s>e || s>r || e<l)
        return;

    if(l<=s && e<=r)
    {
        tree[node]+=val;
        if(s!=e)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }

    ll mid=(s+e)/2;
    rangeupdate(2*node,s,mid,l,r,val);
    rangeupdate(2*node+1,mid+1,e,l,r,val);

    tree[node]=min(tree[2*node],tree[2*node+1]);
}
ll rangequery(ll node,ll s,ll e,ll l,ll r)
{
    if(s>e || s>r || e<l)
        return 1000000000;

    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(s!=e)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(l<=s && e<=r)
        return tree[node];

    ll mid=(s+e)/2;
    ll p1=query(2*node,s,mid,l,r);
    ll p2=query(2*node+1,mid+1,e,l,r);
    return min(p1,p2);
}
///***********************************************************************************************************************///


///---------------------------------------------->DSU<--------------------------------------------------------------------///
void initalize(ll n)
{
    ll i;
    fs(i,1,n+1)
    {a[i]=i;si[i]=1;}
}
ll root(ll i)
{
    W(a[i]!=i)
    {
        a[i]=a[a[i]];
        i=a[i];
    }
    return i;
}
bool find(ll x,ll y)
{
    if(root(x)==root(y))
        return true;
    else
        return false;
}
void U(ll x,ll y)
{
    ll root_x=root(x);
    ll root_y=root(y);
    if(si[root_x]>si[root_y])
    {
        a[root_y]=a[root_x];
        si[root_x]+=si[root_y];
        si[root_y]=0;
    }
    else
    {
        a[root_x]=a[root_y];
        si[root_y]+=si[root_x];
        si[root_x]=0;
    }
}
///************************************************************************************************************************///


///---------------------------------------------->MST(KRUSKAL)<------------------------------------------------------------///
ll kruskal(ll m)
{
    ll x,y,i,j,k;
    ll cost,mincost=0,sum=0,c,d;
    fs(i,1,m+1)
    {
        cost=p[i].fi;

        c=0;
        fs(j,i,m+1)
        {
            if(p[j].fi!=cost)
                break;
            else
            {
                x=p[j].se.fi;
                y=p[j].se.se;
                if(find(x,y))
                    c++;
            }
        }
        k=j;
        //cout<<k<<endl;

        d=0;
        fs(j,i,k)
        {
        	x=p[j].se.fi;
            y=p[j].se.se;
            if(!find(x,y))
            {
                d++;
                mincost+=cost;
                U(x,y);
            }
        }
        //cout<<c<<" "<<d<<endl;
        sum+=(k-i)-c-d;
        i=k-1;
        //cout<<sum<<endl;
    }
    return sum;
}
///***********************************************************************************************************************///
/*
///------------------------------------------------>MST(PRIM)<------------------------------------------------------------///
ll prim(ll x)
{
    priority_queue<pll,vector<pll>,greater<pll> > Q;
    ll y,mincost=0;
    pll P;
    Q.push(mp(0, x));
    W(!Q.empty())
    {
        P=Q.top();
        Q.pop();
        x=P.se;

        if(mark[x]==true)
            continue;

        mincost+=P.fi;
        mark[x]=true;
        k=adj[x].size();
        fn(i,k)
        {
            y=adj[x][i].se;
            if(!mark[y])
                Q.push(adj[x][i]);
        }
    }
    return mincost;
}
///***********************************************************************************************************************///

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll n,m,u,v,w,i;
    cin>>n>>m;
    initalize(n);
    fs(i,1,m+1)
    {
        cin>>u>>v>>w;
        p[i].fi=w;
        p[i].se.fi=u;
        p[i].se.se=v;
    }
    sort(p.begin()+1,p.begin()+m+1);
    cout<<kruskal(m);
    return 0;
}










