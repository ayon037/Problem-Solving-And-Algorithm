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
int dx[]= {0,1,-1,0,0};
int dy[]= {0,0,0,1,-1};


int main()
{
    Charpoka;
    TC
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>v(n+1);
        for(ll i=1;i<=n;i++)
        {
            cin>>v[i];
        }
        ll cnt=0;
        for(ll i=1;i<=n;i++)
        {
            if(v[i]!=i)
            {
                cnt++;
            }
        }
        if(cnt==0)
        {
            cout<<0<<endl;
        }
        else
        {
            if(cnt==2)
            {
                ll idx1=-1,idx2=-1;
                for(ll i=1;i<=n;i++)
                {
                    if(idx1==-1)
                    {
                        if(v[i]!=i)
                        {
                            idx1=i;
                        }
                    }
                    else
                    {
                        if(v[i]!=i)
                        {
                            idx2=i;
                            break;
                        }
                    }
                }
                if(idx2-idx1<=k)
                {
                    cout<<0<<endl;
                }
                else
                {
                    cout<<1<<endl;
                }
            }
            else
            {
                ll idx1=-1,idx3=-1;
                for(ll i=1;i<=n;i++)
                {
                    if(v[i]!=i && idx1==-1)
                    {
                        idx1=i;
                    }
                    else if(v[i]!=i && idx1!=-1)
                    {
                        idx3=i;
                    }

                }
                //cout<<"Idx3 - Idx1 = "<<idx3-idx1<<endl;
                if(idx3-idx1<=k)
                {
                    cout<<0<<endl;
                }
                else
                {
                    ll idx2=-1;
                    ll mx=LLONG_MIN;
                    for(ll i=idx1+1;i<n;i++)
                    {
                        if(v[i]!=i)
                        {
                            if(v[i]<v[idx1])
                            {
                                ll diff=v[idx1]-v[i];
                                if(mx<diff)
                                {
                                    mx=diff;
                                    idx2=i;
                                }
                            }
                        }
                    }
                    swap(v[idx1],v[idx2]);
                    //cout<<"Idx2 - Idx1 = "<<idx2-idx1<<endl;
                    idx1=-1,idx3=-1;
                    for(ll i=1;i<=n;i++)
                    {
                        if(v[i]!=i && idx1==-1)
                        {
                            idx1=i;
                        }
                        else if(v[i]!=i && idx1!=-1)
                        {
                            idx3=i;
                        }
                    }
                    //cout<<"Idx3 - Idx1 = "<<idx3-idx1<<endl;
                    if(idx3-idx1<=k)
                    {
                        cout<<1<<endl;
                    }
                    else
                    {
                        cout<<-1<<endl;
                    }


                }

            }
        }
    }
    return 0;
}
/*
3
7
6 7 3 4 4 6 5
6 3 4 4 7 6 5
3
1 2 1
1 1 2
3
2 2 1
2 1 2
*/
