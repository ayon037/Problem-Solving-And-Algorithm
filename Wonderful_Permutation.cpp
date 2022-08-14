#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        vector<int> v1, v2;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            v1.push_back(a);
            v2.push_back(a);
        }
        sort(v2.begin(), v2.end());
        map<int, bool> mp;
        if (n == k)
        {
            cout << 0 << endl;
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                mp[v2[i]] = true;
            }
            for (int i = 0; i < k; i++)
            {
                if (!mp[v1[i]])
                {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}