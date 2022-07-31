#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        int flag = 0;
        for (int i = 0; i <= n - m; i++)
        {
            if (s1[i] == s2[0])
            {
                s1[n - m] = s2[0];
                i = n - m + 1;
            }
        }
        string str = s1.substr(n - m, m);
        if (str == s2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}