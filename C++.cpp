#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit | ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
#define infinity 1 << 30
typedef long double Tf;
const Tf EPS = 1e-9;
const ll MX = 1e5 + 123;

int main()
{
    Charpoka;
    int t, cnt = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> v1, v2;
        for (int i = 1; i <= n; i++)
        {
            ll a;
            cin >> a;
            v1.push_back(a);
        }
        sort(v1.begin(), v1.end());
        for (int i = 1; i <= n; i++)
        {
            ll a;
            cin >> a;
            v2.push_back(a);
        }
        sort(v2.rbegin(), v2.rend());
        long long int scaler = 0;
        for (int i = 0; i < n; i++)
        {
            scaler += (v1[i] * v2[i]);
        }
        cout << "Case #" << ++cnt << ": " << scaler << endl;
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