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
vector<bool>Prime(MX+1,true);
int dx[]= {0,1,-1,0,0};
int dy[]= {0,0,0,1,-1};

/*void PrimeFinder(ll n)
{
    Prime[1]=false;
    for(ll i=2;i*i<=n;i++)
    {
        if(Prime[i]==true)
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                Prime[j]=false;
            }
        }
    }
}*/


struct Node
{
    ll val1,val2;
};

bool compareData(pair<ll,ll>pp1,pair<ll,ll>pp2)
{
    if(pp1.first>pp2.first)
    {
        return true;
    }
    else if(pp1.first<pp2.first)
    {
        return false;
    }
    return pp1.second<pp2.second;
}

int main()
{
    Charpoka;
    ll n;
    cin>>n;
    vector<ll>v(n);
    ll mn=LLONG_MAX;
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
        v[i]=abs(v[i]);
        mn=min(mn,v[i]);
    }
    cout<<mn<<endl;
    return 0;
}

/*
3
2 1 1
10 1 2
3 7 8
*/

