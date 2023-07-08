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
const ll MX = 1e6+15;
vector<bool>Prime(MX+1,false);
int dx[]= {0,1,-1,0,0};
int dy[]= {0,0,0,1,-1};
const ll MOD = 1e9+7;
vector<ll>graph[MX];
vector<ll>leafs;

struct Node
{
    ll index,score,penalty;
};

ll compareData(const Node& node1, const Node& node2)
{
    if (node1.score!=node2.score)
    {
        return node1.score>node2.score;
    }
    else
    {
        if(node1.penalty!=node2.penalty)
        {
            return node1.penalty<node2.penalty;
        }
        else
        {
            return node1.index<node2.index;
        }
    }
    //return node1.index<node2.index;
}

int main()
{
    Charpoka;
    TC
    {
        ll n,m,h;
        cin>>n>>m>>h;
        map<ll,vector<ll>>mp;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                ll a;
                cin>>a;
                mp[i].pb(a);
                //mp[i].pb(1);
            }
            sort(mp[i].begin(),mp[i].end());
        }
        //cout<<endl;
        Node arr[n];
        for(ll i=1;i<=n;i++)
        {
            ll sc=0,pen=0,sum=0;
            for(ll j=0;j<mp[i].size();j++)
            {
                //cout<<mp[i][j]<<" ";
                pen+=mp[i][j];
                //cout<<pen<<endl;
                if(pen<=h)
                {
                    //pen+=mp[i][j];
                    sc++;
                    sum+=pen;
                }
                else
                {
                    break;
                }
            }
            arr[i-1].index=i;
            arr[i-1].penalty=sum;
            arr[i-1].score=sc;
            //cout<<"Sum = "<<sum<<endl;
        }
        //cout<<endl;
        sort(arr, arr+n, compareData);
        for(ll i=0;i<n;i++)
        {
            //cout<<arr[i].index<<" "<<arr[i].score<<" "<<arr[i].penalty<<endl;
            if(arr[i].index==1)
            {
                cout<<i+1<<endl;
                break;
            }
        }
        //cout<<endl;

    }
    return 0;
}

/*
5
3 3 120
20 15 110
90 90 100
40 40 40
2 1 120
30
30
1 3 120
10 20 30
3 2 27
8 9
10 7
10 8
3 3 15
7 2 6
7 5 4
1 9 8
*/
