#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define SetBits(x) __builtin_popcount(x)
#define CntBits(x) (int)log2(x)+1
#define pb push_back
#define ll long long int
#define infinity 1 << 30
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define no cout<<"no\n"
#define TC int t; cin>>t; while(t--)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*s.find_by_order(2) -> element at index 2
//s.order_of_key(3) -> lower bound of 3*/
//#define ordered_set tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
typedef long double Tf;
const Tf EPS = 1e-9;
const ll MX = 1e6+15;
vector<bool>Prime(MX+1,true);
int dx[]= {0,1,-1,0,0};
int dy[]= {0,0,0,1,-1};
const ll MOD = 1e9+7;
//vector<ll>graph[MX];
vector<ll>leafs;

struct Key
{
    int mp1;
    int mp2;
    int a;
    bool operator<(const Key& other) const
    {
        if (mp1!=other.mp1)
        {
            return mp1>other.mp1;  // Sort in descending order based on mp1[a]
        }
        else
        {
            if(mp2!=other.mp2)
            {
                return mp2<other.mp2;
            }
            else
            {
                return a<other.a;
            }
            //return mp2<other.mp2;  // Sort in ascending order based on mp2[a]
        }
    }
};

int solve(string& s1,string& s2)
{
    int res=0;
    for(int i=0; i<s1.size(); i++)
    {
        res+=abs(s1[i]-s2[i]);
    }
    return res;
}


void PrimeFinder(ll n)
{
    Prime[1]=false;
    for(ll i=2; i*i<=n; i++)
    {
        if(Prime[i]==true)
        {
            for(ll j=i*i; j<=n; j+=i)
            {
                Prime[j]=false;
            }
        }
    }
}

int f(int n,vector<int>&dp)
{
    if(n==0 || n==1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    int left=f(n-1,dp);
    int right=f(n-2,dp);
    return dp[n]=left+right;
}

ll func(ll x,ll y,ll d)
{
    bool f=((y-x)%d)==0;
    return (y-x)/d+1-f;
}

const int N=1e5+10;
const int INF=1e9+10;
vector< pair<int,int> >g[N];
//int dist[N];
void dijkstra(int source)
{
    vector<int>vis(N,0);
    vector<int>dist(N,INF);
    set< pair<int,int> >st;

    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0)
    {
        auto node = *st.begin();
        int v=node.second;
        int v_dist=node.first;
        st.erase(st.begin());
        if(vis[v]==0)
        {
            vis[v]=1;
            for(auto child:g[v])
            {
                int child_v=child.first;
                int wt=child.second;
                if(dist[v]+wt<dist[child_v])
                {
                    dist[child_v]=dist[v]+wt;
                    st.insert({dist[child_v],child_v});
                }
            }
        }
    }
    cout<<dist[3];

}

int main()
{
    Charpoka;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].pb({y,w});
    }
    dijkstra(1);
    //cout<<dist[3];
    return 0;
}
/*
6 9
1 2 1
1 3 5
2 3 2
2 4 2
2 5 1
3 5 2
4 5 3
4 6 1
5 6 2
*/

