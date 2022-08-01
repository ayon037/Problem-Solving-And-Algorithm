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
        map<int, int> mp1, mp2, mp3;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            mp1[a]++;
            // mp2[a]=i;
            if (mp1[a] == 1)
            {
                mp2[a] = i;
            }
            else
            {
                if (cnt > mp2[a])
                {
                    cnt = cnt;
                }
                else
                {
                    cnt = mp2[a];
                }

                mp2[a] = i;
                mp1[a] = 1;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}