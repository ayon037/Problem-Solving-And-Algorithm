#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pb push_back
#define ll long long int
#define infinity 1 << 30
typedef long double Tf;
const Tf EPS = 1e-9;
const ll MX = 1e5 + 123;

unordered_map<ll, ll> mp;

ll dp(ll a)
{
    if (a < 1)
    {
        return 0;
    }
    if (a == 1)
    {
        return 1;
    }
    if (mp.count(a))
    {
        return mp[a];
    }
    ll cnt = max(a, (dp(a / 2) + dp(a / 3) + dp(a / 4)));
    mp[a] = cnt;
    return cnt;
}
int main()
{

    Charpoka;
    // int t;
    // cin >> t;
    ll a;
    while (cin >> a)
    {
        // // ll a;
        // cin >> a;
        ll ans = dp(a);
        cout << ans << endl;
        mp.clear();
    }
    return 0;
}

/*

Steps to Compile cpp file
1. Go To Terminal and click Run Build Task
2. Click C/C++: g++.exe build active file
3. On Terminal, write .\File_Name
4. Write test cases and see the outputs

*/