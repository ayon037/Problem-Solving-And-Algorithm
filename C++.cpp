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
    int cnt=0;
    TC
    {
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<pair<int,int>>v;
        bool flag=false;
        int left,right;
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                right=i;
            }
            if(a[n-i-1]!=b[n-i-1])
            {
                left=n-i-1;
            }
        }

        int mn=INT_MAX,mx=INT_MIN;

        for(int i=left;i<=right;i++)
        {
            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
        }

        while(left>0 && a[left-1]<=mn)
        {
            left--;
            mn=min(mn,a[left]);
        }

        while(right<n-1 && a[right+1]>=mx)
        {
            right++;
            mx=max(mx,a[right]);
        }
        cout<<left+1<<" "<<right+1<<endl;
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
