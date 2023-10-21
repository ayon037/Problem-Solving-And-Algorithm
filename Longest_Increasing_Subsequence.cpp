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

int dp[MX];

int lis(vector<int>&v,int i)
{
    if(dp[i]!=-1)
        return dp[i];
    int ans=1;
    for(int j=0;j<i;j++)
    {
        if(v[i]>v[j])
        {
            ans=max(ans,lis(v,j)+1);
        }
    }
    return dp[i]=ans;
}
int main()
{
    Charpoka;
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,lis(v,i));
    cout<<ans<<endl;
    return 0;
}

/*
8
10 9 2 5 3 7 101 18
*/
