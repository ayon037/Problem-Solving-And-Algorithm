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

int num_codes(int* arr,int sz)
{
    if(sz==1 || sz==0)
    {
        return 1;
    }
    int output=num_codes(arr,sz-1);
    if(arr[sz-2]*10+arr[sz-1]<=26)
    {
        output+=num_codes(arr,sz-2);
    }
    return output;
}

int num_codes2(int* arr,int sz,int* dp)
{
    if(sz==1 || sz==0)
    {
        return 1;
    }
    if(dp[sz]!=0)
    {
        return dp[sz];
    }
    int output=num_codes(arr,sz-1);
    if(arr[sz-2]*10+arr[sz-1]<=26)
    {
        output+=num_codes(arr,sz-2);
    }
    return dp[sz]=output;
}

int num_codes_i(int* input,int sz)
{
   int* output=new int[sz+1];
   output[0]=1;
   output[1]=1;
   for(int i=2;i<=sz;i++)
   {
       output[i]=output[i-1];
       if(input[i-2]*10+input[i-1]<=26)
       {
           output[i]+=output[i-2];
       }
   }
   int ans=output[sz];
   delete [] output;
   return ans;
}


int main()
{
    Charpoka;
    int n;
    cin>>n;
    int arr[n+1],dp[n+1];
    memset(dp,0,sizeof(dp));
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        arr[i+1]=s[i]-'0';
        //cout<<s[i]-'0'<<endl;
    }
    cout<<num_codes2(arr,n,dp)<<endl;

}

/*
*/
