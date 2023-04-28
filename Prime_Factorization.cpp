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

int prime[100],expo[100],len=0;

void PrimeFact(int n)
{
    if(n==1)
    {
        len++;
        prime[len]=2;
        expo[len]=0;
        return;
    }
    int d=2;
    while(d*d<=n && n>1)
    {
        int k=0;
        while(n%d == 0)
        {
            n/=d;
            k++;
        }

        if(k>0)
        {
            len++;
            prime[len]=d;
            expo[len]=k;
        }
        d++;
    }

    if(n>1)
    {
        len++;
        prime[len]=n;
        expo[len]=1;
    }

}

int main()
{
    Charpoka;
    PrimeFact(1);
    for(int i=1;i<=len;i++)
    {
        cout<<prime[i]<<" "<<expo[i]<<endl;
    }
    return 0;
}
