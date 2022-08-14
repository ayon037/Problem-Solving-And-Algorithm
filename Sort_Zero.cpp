#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        vector<int> v;
        map<int, bool> mp;
        map<int, int> mp2;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        for (int i = 0; i < v.size(); i++)
        {
            mp2[v[i]]++;
            if (i == 0)
            {
                mp[v[i]] = true;
            }
            else
            {
                if (v[i] < v[i - 1])
                {
                    cnt = mp.size();
                    mp[v[i]] = true;
                }
                else if (v[i] > v[i - 1])
                {
                    if (mp[v[i]] == true)
                    {
                        cnt = mp.size();
                    }
                    else
                    {
                        mp[v[i]] = true;
                    }
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}