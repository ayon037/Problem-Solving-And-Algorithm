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
        if (n % 2 == 0 || m % 2 == 0)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 12 << endl;
        }
    }
}