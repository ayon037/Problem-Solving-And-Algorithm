#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define SetBits(x) __builtin_popcount(x)
#define CntBits(x) (int)log2(x)+1
#define pb push_back
#define ll long long int
#define infinity 1<<30
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
using ordered_multiset = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*s.find_by_order(2) -> element at index 2
//s.order_of_key(3) -> lower bound of 3*/
//#define ordered_set tree1 <int,null_type,less<int>,rb_tree1_tag,tree1_order_statistics_node_update>
typedef long double Tf;
const Tf EPS = 1e-9;
const ll MX = 1e5+15;
vector<bool>Prime(MX+1,true);
const ll MOD = 1e9+7;
//vector<ll>graph[MX];
vector<ll>leafs;


char ch[110][110];
bool vis[110][100];

int dx[] = {1,-1,0,1,-1};
int dy[] = {0, 0,1,1,1};
ll tree1[4*MX];

vector<ll>prime(5000);
ll expo[100],len=0;
void PrimeFact(ll n)
{
    if(n==1)
    {
        len++;
        prime[len]=2;
        expo[len]=0;
        return;
    }
    ll d=2;
    while(d*d<=n && n>1)
    {
        ll k=0;
        while(n%d == 0)
        {
            n/=d;
            k++;
        }

        if(k>0)
        {
            len++;
            prime[len]=d;
            expo[len]=k;
        }
        d++;
    }

    if(n>1)
    {
        len++;
        prime[len]=n;
        expo[len]=1;
    }

}

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

const int BITS=4;


const int N = 1e6+5;
const int mod = 1e9+7;
int fact[N],inv[N],ifact[N];

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

void init()
{
    inv[1]=fact[0]=ifact[0]=1;
    for(int i = 2; i < N; i++)
        inv[i] = (ll)inv[mod%i]*(mod - mod/i)%mod;
    for(int i = 1; i < N; i++)
        fact[i] = (ll)fact[i-1]*i%mod;
    for(int i = 1; i < N; i++)
        ifact[i] = (ll)ifact[i-1]*inv[i]%mod;
}

int ncr(int n,int r)
{
    if(r<0 || r>n)
        return 0;
    return (ll)fact[n]*ifact[r]%mod*ifact[n-r]%mod;
}

bool check(ll x,ll a,ll b)
{
    while(x>0)
    {
        ll c=x%10;
        if(c==a || c==b)
        {

        }
        else
        {
            return false;
        }
        x/=10;
    }
    return true;
}

bool dfs(int row,int col,int n)
{
    if(col == n)
    {
        if(ch[row][col]=='0')
            return 1;
        else
            return 0;
    }
    vis[row][col] = 1;
    bool flag = false;
    bool track = false;
    for(int i = 0; i<5; i++)
    {
        int x = row + dx[i];
        int y = col + dy[i];
        if(x <= 2 && x > 0 && y > 0 && y <= n && ch[x][y] == '0' && vis[x][y] == 0)
        {
            vis[x][y] = 1;
            track = dfs(x,y,n);
            if(track == true)
            {
                flag = true;
            }
            else
            {
                if(flag == false)
                {
                    flag = false;
                }
            }

        }
    }
    return flag;
}

struct Node1
{
    ll val,idx;
};

bool compareDescending(const Node1& a, const Node1& b)
{
    return a.val > b.val;
}
map<ll,bool>mp;
void build(vector<ll>&v,ll node,ll start,ll finish)
{
    if(start == finish)
    {
        if(!mp[v[start]])
        {
            tree1[node]+=1;
            mp[v[start]]=true;
        }
        else
        {
            tree1[node]=0;
        }
        return;
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(start+finish)/2;
    build(v,left,start,mid);
    build(v,right,mid+1,finish);
    tree1[node]=tree1[left]+tree1[right];

}

ll query(vector<ll>&v,ll node, ll start, ll finish, ll idx1, ll idx2)
{
    if (idx1 > finish || idx2 < start)
    {
        return 0;
    }
    if (start >= idx1 && finish <= idx2)
        return tree1[node];
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (start+finish)/2;
    ll val1 = query(v,left,start, mid,idx1,idx2);
    ll val2 = query(v,right,mid+1,finish,idx1,idx2);
    return val1+val2;
}

void update(vector<ll>&v,ll node, ll start, ll finish, ll idx, ll newvalue)
{
    if (idx > finish || idx < start)
        return;
    if (start >= idx && finish <= idx)
    {
        //mp[tree1[node]]=false;
        if(!mp[newvalue])
        {
            //tree1[node]=1;
            if(tree1[node]<=0)
            {
                tree1[node]+=1;
            }
            mp[newvalue]=true;
        }
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (start + finish) / 2;
    update(v,left, start, mid, idx, newvalue);
    update(v,right, mid + 1, finish, idx, newvalue);
    tree1[node]=tree1[left]+tree1[right];


}
int main()
{
    Charpoka;
    string s;
    cin>>s;
    ll n=s.size();
    vector<ll>v(n+1);
    map<ll,ll>cnt;
    for(ll i=0;i<s.size();i++)
    {
        ll val=(ll)s[i];
        v[i+1]=val;
        cnt[val]++;
    }
    memset(tree1,0,sizeof(tree1));
    build(v,1,1,n);
    TC
    {
        ll qu;
        cin>>qu;
        if(qu==2)
        {
            ll idx1,idx2;
            cin>>idx1>>idx2;
            ll ans=query(v,1,1,n,idx1,idx2);
            cout<<ans<<endl;
        }
        else
        {
            ll idx;
            char ch;
            cin>>idx>>ch;
            ll curr=(ll)v[idx];
            ll val=(ll)ch;
            if(curr==val)
            {

            }
            else
            {
                if(cnt[curr]<=1)
                {
                    mp[curr]=false;
                    cnt[val]++;
                    cnt.erase(curr);
                }
                else
                {
                    cnt[val]++;
                    cnt[curr]--;
                }
            }
            v[idx]=val;
            update(v,1,1,n,idx,val);
        }
    }
    return 0;
}
