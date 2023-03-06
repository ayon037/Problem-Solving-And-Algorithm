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
const ll mx = 1000005;
ll dp[mx];
vector<bool>Prime(MX+1,false);
//ll m=0;

int main()
{
    Charpoka;
    TC
    {
        ll n;
        cin>>n;
        vector<ll>v(n+1);
        vector< pair<ll,ll> >track,result;
        map<ll,int>mp;
        for(ll i=1;i<=n;i++)
        {
            cin>>v[i];
            mp[v[i]]++;
            track.pb({v[i],i});
        }

        if(mp.size()==1)
        {
            cout<<0<<endl;
        }
        else
        {
            if(mp[1]>0)
            {
                cout<<-1<<endl;
            }
            else
            {
                sort(track.begin(),track.end());
                while(track[0].first!=track[n-1].first)
                {
                    ll val=track[0].first;
                    for(ll i=0;i<n;i++)
                    {
                        if(track[i].first!=val)
                        {
                            track[i].first=(track[i].first+val-1)/val;
                            result.pb({track[i].second,track[0].second});
                        }
                    }
                    sort(track.begin(),track.end());
                }

                cout<<result.size()<<endl;
                for(ll i=0;i<result.size();i++)
                {
                    cout<<result[i].first<<" "<<result[i].second<<endl;
                }
            }
        }

    }
    return 0;

}

/*
*/
