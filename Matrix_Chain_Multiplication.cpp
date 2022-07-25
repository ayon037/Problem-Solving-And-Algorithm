#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit | ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
#define mx 100001
#define infinity 1 << 30
const int N=102;
const int MOD=1e9+7;
int a[N];
int dp[N][N];
int s[N][N];

int mcm(int i,int j)
{
   if(i==j)
   {
      return 0;
   }

   if(dp[i][j]!=-1)
   {
      return dp[i][j];
   }
   
   dp[i][j]=MOD;
   for(int k=i;k<j;k++)
   {
      int cost=mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j];
      if(cost<dp[i][j])
      {
         s[i][j]=k;
      }
      dp[i][j]=min(dp[i][j],mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j]);
   }
   return dp[i][j];

}

void print_order(int i,int j)
{
    if(i==j) 
    {
        cout<<"A"<<i+1;
        return;
    }
    int m=s[i][j];
    cout<<"(";
    print_order(i,m);
    cout<<"x";
    print_order(m+1,j);
    cout<<")";
    return;
}

int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      cin>>a[i];
   }
   memset(dp,-1,sizeof(dp));
   cout<<mcm(1,n-1)<<endl;
   print_order(0,n-1);
   
}