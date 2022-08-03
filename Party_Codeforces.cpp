#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, m;
        cin >> n >> m;
        vector<long long int> v1;
        vector<pair<long long int, long long int>> v2;
        vector<long long int> v3(n + 1, 0);
        for (long long int i = 1; i <= n; i++)
        {
            long long int a;
            cin >> a;
            v1.push_back(a);
        }
        for (long long int i = 1; i <= m; i++)
        {
            long long int x, y;
            cin >> x >> y;
            v2.push_back({x, y});
            v3[x]++;
            v3[y]++;
        }
        if (m % 2 == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            long long int ans = LLONG_MAX;
            for (long long int i = 1; i <= n; i++)
            {
                if (v3[i] % 2 == 1)
                {
                    ans = min(ans, v1[i - 1]);
                }
            }
            for (auto u : v2)
            {
                if (v3[u.first] % 2 == 0 && v3[u.second] % 2 == 0)
                {
                    ans = min(ans, v1[u.first - 1] + v1[u.second - 1]);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}