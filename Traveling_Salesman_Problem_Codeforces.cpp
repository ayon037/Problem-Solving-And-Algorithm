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
        int sum = 0, cnt = 0, a = 0, b = 0, c = 0, d = 0;
        while (n--)
        {
            int x, y;
            cin >> x >> y;
            if (y == 0)
            {
                a = max(a, x);
                b = min(b, x);
            }
            else
            {
                c = max(c, y);
                d = min(d, y);
            }
        }
        sum = (a + c + abs(b) + abs(d)) * 2;
        cout << sum << endl;
    }
    return 0;
}