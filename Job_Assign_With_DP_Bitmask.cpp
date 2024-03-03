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
const int mx = 20;
ll dp[mx][mx];
vector<bool>Prime(MX+1,false);

void add(int& subset,int x)
{
    subset = subset^(1<<(x-1));
}

void remove(int& subset,int x)
{
    subset = subset^(1<<(x-1));
}

void display(int subset)
{
    for(int bit_no=0;bit_no<=9;bit_no++)
    {
        if(subset&(1<<bit_no))
        {
            cout<<bit_no+1<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    Charpoka;
    int Set = 15;
    remove(Set,2);
    add(Set,5);
    display(Set);

    return 0;
}

