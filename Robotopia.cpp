#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        int flag = 0, f = 0;
        int p, q, r, s;
        int a, b, c, d;
        for (int i = 1; i <= 10001; i++)
        {
            a = cx, b = cy;
            a = a - (ax * i);
            b = b - (ay * i);
            if (a < bx || b < by)
                break;
            if ((a % bx == 0) && (b % by == 0) && (a / bx) == (b / by))
            {
                flag++;
                p = i;
                q = b / by;
            }
        }
        if (flag > 1 || flag == 0)
        {
            cout << "?" << endl;
        }
        else
        {
            cout << p << " " << q << endl;
        }
    }
    return 0;
}