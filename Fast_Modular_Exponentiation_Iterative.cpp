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

int FastExpo(int a,long long int n,int MOD)
{
    int ans=1;
    /// a = 2, n = 13 ---> 2^13 , ans = 1
    /// 1. n is odd, (2^12), a = 2, n = 12, ans = 1*2 = 2
    /// 2. n is even, (2^2)^6 = 4^6, a = 4, n = 6, ans = 2
    /// 3. n is even, (4^2)^3 = 16^3, a = 16, n = 3, ans = 2
    /// 4. n is odd, (16^2), a = 16, n = 2, ans = 2*16 = 32
    /// 5. n is even, (16^2)^1 = 256^1, a = 256, n = 1 , ans = 32
    /// 6. n is odd, (256^0), a = 256, n = 0, ans = 32*256 = 8192

    while(n>=1)
    {
        if(n%2==0)
        {
            a=(1LL*a*a)%MOD;
            n/=2;
        }
        else
        {
            n=n-1;
            ans=(1LL*ans*a)%MOD;
        }
    }
    return ans;
}

int main()
{
    Charpoka;
    cout<<FastExpo(7,0,1000000007)<<endl;
    return 0;
}

