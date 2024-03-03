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
int dist[21][21];
int dp[21][(1<<21)];
int n;
vector<bool>Prime(MX+1,false);

int tsp(int VISITED_ALL,int mask,int pos)
{
    if(mask==VISITED_ALL)
    {
        return dist[pos][0];
    }
    if(dp[pos][mask]!=-1)
    {
        return dp[pos][mask];
    }
    int ans=INT_MAX;
    for(int city=0;city<n;city++)
    {
        if((mask&(1<<city))==0)
        {
            int newAns = dist[pos][city]+tsp(VISITED_ALL,mask|(1<<city),city);
            ans=min(ans,newAns);
        }
    }
    return dp[pos][mask]=ans;
}

int main()
{
    Charpoka;
    TC
    {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>dist[i][j];
            }
        }
        int VISITED_ALL=(1<<n)-1;
        cout<<tsp(VISITED_ALL,1,0)<<endl;

    }
    return 0;
}

/*
1
4
0 20 42 25
20 0 30 34
42 30 0 10
25 34 10 0
*/

