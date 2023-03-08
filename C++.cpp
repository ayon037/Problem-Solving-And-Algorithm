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
vector<bool>Prime(MX+1,false);
int cost[21][21];
int dp[21][(1<<21)];
int solve(int i,int mask,int n)
{
    if(i==n)
    {
        return 0;
    }
    if(dp[i][mask]!=-1)
    {
        return dp[i][mask];
    }
    int ans=INT_MAX;
    for(int j=0;j<n;j++)
    {
        if(mask&(1<<j))
        {
            ans=min(ans,cost[j][i]+solve(i+1,(mask^(1<<j)),n));
        }
    }
    return dp[i][mask]=ans;
}

int main()
{
    Charpoka;
    int n,m,x,i,j,k,q;
    memset(dp,-1,sizeof(dp));
    TC
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>cost[i][j];
            }
        }
        cout<<solve(0,(1<<n)-1,n)<<endl;
    }
    return 0;
}

/*
1
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
*/
