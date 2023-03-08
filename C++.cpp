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
int n;
double dp[(1<<20)];
double prob[20][20];

double pMove(int p_mask,int j,int &n)
{
    int k = SetBits(p_mask);
    ll den = (k*(k-1))/2;

    double moveProb=0;

    for(int fish=0;fish<n;fish++)
    {
        if((1<<fish)&p_mask)
        {
            moveProb+=prob[fish+1][j+1];
        }
    }
    return moveProb/(1.0*den);
}
double solve(int mask,int &n)
{
    int alive=SetBits(mask);
    if(alive==n)
    {
        return 1.0;
    }
    if(dp[mask]> -0.9)
    {
        return dp[mask];
    }

    double ans=0;
    for(int fish=0;fish<n;fish++)
    {
        if(!(mask&(1<<fish)))
        {
            int p_mask=mask^(1<<fish);
            double prev_day=solve(p_mask,n);
            ans+=prev_day*pMove(p_mask,fish,n);
        }
    }
    return dp[mask]=ans;
}
int main()
{
    Charpoka;
    // Codeforces Beta Round 16 (Div-02) Problem-F (Fish)
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>prob[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<solve((1<<i),n)<<" ";
    }
    return 0;

}
