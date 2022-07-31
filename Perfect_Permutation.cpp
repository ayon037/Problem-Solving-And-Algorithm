#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        cout << a << " ";
        for (int j = 1; j < a; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}