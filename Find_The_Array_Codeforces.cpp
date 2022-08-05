#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long int sum = 0;
        vector<long long int> v;
        for (int i = 0; i < n; i++)
        {
            long long int a;
            cin >> a;
            v.push_back(a);
        }
        long long int cnt = 0, track;
        for (int i = 0; i < n; i++)
        {
            long long int p = 1;
            while (p * 2 <= v[i])
            {
                p = p * 2;
            }
            v[i] = p;
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}