#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, h, m;
        cin >> n >> h >> m;
        int cnt1 = 100, cnt2 = 100;
        map<int, vector<int>> v;
        for (int i = 1; i <= n; i++)
        {
            int h1, m1;
            cin >> h1 >> m1;
            if (h == 0)
            {
                h = 24;
            }
            if (h1 == 0)
            {
                h1 = 24;
            }

            // cnt1=min(cnt1,abs(h1-h));
            // cnt2=min(cnt2,abs(m1-m));
            int val1 = h1 - h;
            int val2 = m1 - m;

            if (val2 != 0)
            {
                if (val1 < 0)
                {
                    if (val2 < 0)
                    {
                        // cnt2=60+val2;
                        val1 = val1 + 24 - 1;
                        cnt1 = min(cnt1, val1);
                    }
                    else if (val2 >= 0)
                    {
                        // cnt2=60-val2;
                        val1 = val1 + 24;
                        cnt1 = min(cnt1, val1);
                    }
                    cnt2 = (val2 + 60) % 60;
                }
                else if (val1 >= 0)
                {
                    if (val2 < 0)
                    {
                        cnt2 = (val2 + 60) % 60;
                        if (val1 == 0)
                        {
                            val1 = 23;
                            cnt1 = min(cnt1, 23);
                        }
                        else
                        {
                            val1 = val1 - 1;
                            cnt1 = min(cnt1, val1);
                        }
                    }
                    else if (val2 >= 0)
                    {
                        cnt2 = val2;
                        cnt1 = min(cnt1, val1);
                    }
                }
            }
            else
            {
                if (val1 < 0)
                {
                    val1 = val1 + 24;
                    cnt1 = min(cnt1, val1);
                    // cnt2=val2;
                }
                else if (val1 >= 0)
                {
                    cnt1 = min(cnt1, val1);
                    // cnt2=val2;
                }
                cnt2 = 0;

                // cnt1=min(cnt1,val1);
                // cnt2=val2;
            }
            // cnt2=min(cnt2,val2);

            v[val1].push_back(cnt2);
        }
        cnt2 = INT_MAX;
        // cout<<cnt1<<", After loop ends"<<endl;
        for (int i = 0; i < v[cnt1].size(); i++)
        {
            cnt2 = min(cnt2, v[cnt1][i]);
        }
        cout << cnt1 << " " << cnt2 << endl;
    }
    return 0;
}