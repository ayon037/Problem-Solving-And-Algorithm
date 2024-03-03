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
vector<ll>graph[1220];
bool visited[1220];
ll color[500];
vector<ll>leafs;
map<ll,ll>mpp;
ll parent[500];
int dp[MX];

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

string func1(string &s,int idx)
{
    string str="";
    for(int i=0; i<s.size(); i++)
    {
        if(i==idx)
        {
            str+=s[i];
            str+='0';
            str+='1';
        }
        else
        {
            str+=s[i];
        }
    }
    return str;
}

void dfs(ll node,ll par,ll &cycleNumber,vector<vector<ll>>&cycles)
{
    if(color[node]==2)
    {
        return;
    }
    if(color[node]==1)
    {
        vector<ll>v;
        cycleNumber++;
        ll curr=par;
        v.pb(curr);
        while(curr!=node)
        {
            curr=parent[curr];
            v.pb(curr);
        }
        cycles.pb(v);
        return;
    }
    parent[node]=par;
    color[node]=1;
    for(int v:graph[node])
    {
        if(v==parent[node])
        {
            continue;
        }
        dfs(v,node,cycleNumber,cycles);
    }
    color[node]=2;
}


/*void FindAnswer(ll &cyclenumber,vector<vector<ll>>& cycles)
{
    for (ll i=0; i<cyclenumber; i++)
    {
        ll sum=0;
        //cout<<"Cycle No: "<<i+1<<endl;
        if(cycles[i].size()<=4)
        {
            for(auto x:cycles[i])
                sum+=mpp[x];
        }
        ans=max(ans,sum);
    }
}*/


int selectMinVertex(vector<int>&value,vector<bool>&setMST)
{
    int minimum=INT_MAX;
    int vertex;
    for(int i=0; i<6; i++)
    {
        if(setMST[i]==false && value[i]<minimum)
        {
            vertex=i;
            minimum=value[i];
        }
    }
    return vertex;
}
void findMST(int adjacency[6][6])
{
    int Parent[6];
    vector<int>value(6,INT_MAX);
    vector<bool>setMST(6,false);
    Parent[0]=-1;
    value[0]=0;
    for(int i=0; i<5; i++)
    {
        int U=selectMinVertex(value,setMST);
        setMST[U]=true;
        for(int j=0; j<6; j++)
        {
            if(adjacency[U][j]!=0 && setMST[j]==false && adjacency[U][j]<value[j])
            {
                value[j]=adjacency[U][j];
                Parent[j]=U;
            }
        }
    }
    for(int i=1; i<6; i++)
        cout<<"U->V: "<<Parent[i]<<"->"<<i<<" wt = "<<adjacency[parent[i]][i]<<endl;
}
bool hasLength(int number, int length)
{
    return static_cast<int>(log10(number)) + 1 == length;
}
struct Node
{
    ll a;
    string s;
    ll b;
};





vector<ll> lcs(vector<ll> a, vector<ll> b)
{
    vector<ll>ans;
    vector<vector<ll>>dp(a.size()+1,vector<ll>(b.size()+1));
    for(ll i=0; i<=a.size(); i++)
    {
        dp[i][0]=0;
    }
    for(ll i=0; i<=b.size(); i++)
    {
        dp[0][i]=0;
    }
    for(ll i=1; i<=a.size(); i++)
    {
        for(ll j=1; j<=b.size(); j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    ll i=a.size(),j=b.size();
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    Charpoka;
    ll nc;
    cin>>nc;
    vector<ll>calendar[nc];
    map<ll,ll>mp;
    for(ll i=0;i<nc;i++)
    {
        ll n;
        cin>>n;
        for(ll j=0;j<n;j++)
        {
            ll days;
            cin>>days;
            calendar[i].pb(days);
            mp[i]+=days;
        }
    }   

    ll query;
    cin>>query;
    for(ll i=1;i<=query;i++)
    {
        ll cal1,cal2,day,month,year;
        cin>>cal1>>cal2>>day>>month>>year;
        ll tot1=0;
        for(ll j=0;j<month;j++)
        {
            if(j!=month-1)
            {
                tot1+=calendar[cal1-1][j];
            }
            else
            {
                tot1+=day;
                break;
            }
        }
        tot1+=(mp[cal1-1]*(year-1));
        //cout<<tot1<<endl;
        ll tot2=tot1/mp[cal2-1];
        ll remaining=tot1-(tot2*mp[cal2-1]);
        //cout<<remaining<<endl;
        if(remaining==0)
        {
            ll sz=calendar[cal2-1].size()-1;
            cout<<"Query "<<i<<": "<<calendar[cal2-1][sz]<<" "<<sz+1<<" "<<tot2<<endl;
        }
        else
        {
            ll val=remaining;
            ll cal2_day=0,cal2_month=0,cal2_year=0;
            cal2--;
            for(ll j=0;j<calendar[cal2].size();j++)
            {
                if(calendar[cal2][j]<=val)
                {
                    val-=calendar[cal2][j];
                    cal2_day=calendar[cal2][j];
                    cal2_month=j+1;
                }
                else
                {
                    if(val!=0)
                    {
                        cal2_day=val;
                        cal2_month=j+1;
                    }
                    //cal2_day=val;
                    //cal2_month=j+1;
                    break;
                }
            }
            cal2_year=tot2+1;
            //cout<<cal2_day<<" "<<cal2_month<<" "<<cal2_year<<endl;
            cout<<"Query "<<i<<": "<<cal2_day<<" "<<cal2_month<<" "<<cal2_year<<endl;
        }

        
    }
    

    return 0;
}
/*

*/
