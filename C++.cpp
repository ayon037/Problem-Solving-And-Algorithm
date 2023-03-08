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
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*s.find_by_order(2) -> element at index 2
//s.order_of_key(3) -> lower bound of 3*/
typedef long double Tf;
const Tf EPS = 1e-9;
const ll MX = 1e8;
const int mx = 20;
ll dp[mx][mx];
vector<bool>Prime(MX+1,false);
ll val=0;
//ll m=0;
int n;

ll solve(vector<vector<ll> >&v,int row,int col)
{
    if(row>=n || row<0)
    {
        return 0;
    }
    if(col>=n || col<0)
    {
        return 0;
    }
    if(dp[row][col]!=-1)
    {
        return dp[row][col];
    }
    ll ans1=0,ans2=0;

    if(col<=row)
    {
        //ans1=max(0,max(v[row][row]+v[row][row],v[row][row]+v[row][col]))+solve(v,row,col+1);
        //ans2=max(0,max(v[row][row]+v[row][row],v[row][row]+v[row][col]))+solve(v,row+1,col);
        ll num1=v[row][row]+v[row][row];
        ll num2=v[row][row]+v[row][col];
        ans1=max(val,max(num1,num2))+solve(v,row,col+1);
        ans2=max(val,max(num1,num2))+solve(v,row+1,col);
    }
    return dp[row][col]=max(ans1,ans2);

}

int main()
{
    Charpoka;
    TC
    {
        cin>>n;
        vector< vector<ll> >biodata;
        vector<ll>v;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ll a;
                cin>>a;
                v.pb(a);
            }
            biodata.pb(v);
            v.clear();
        }
        ll p=solve(biodata,0,0);
        cout<<p<<endl;
    }
    return 0;

}

/*
*/
