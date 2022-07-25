#include<bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit|ios::failbit)
#define endl '\n'
int a, b, c, d, e, f;
int fn(int n,long long int dp[])
{
    if (n == 0) 
    {
        return dp[n]=a;
    }
    if (n == 1)
    {
        return dp[n]=b;
    }
    if (n == 2)
    {
        return dp[n]=c;
    }
    if (n == 3)
    {
        return dp[n]=d;
    }
    if (n == 4)
    {
        return dp[n]=e;
    }
    if (n == 5)
    {
        return dp[n]=f;
    }
    if (dp[n]!=-1) return dp[n];
    return dp[n] = fn(n-1,dp) + fn(n-2,dp) + fn(n-3,dp) + fn(n-4,dp) + fn(n-5,dp) + fn(n-6,dp);
}
int main() {
    int n, cases;
    scanf("%d", &cases);
    long long int dp[100000];
    memset(dp,-1,sizeof(dp));

    for (int caseno = 1; caseno <= cases; ++caseno) 
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", caseno, fn(n,dp) % 10000007);
    }
    return 0;
}