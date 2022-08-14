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
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        if (n == 1)
        {
            cout << 1;
        }
        else if (n == 2)
        {
            cout << 2 << " " << 1;
        }
        else
        {
            if (n % 2 == 1)
            {
                for (int i = 0; i < v.size() - 1; i++)
                {
                    if (i == 0)
                    {
                        cout << v[i] << " ";
                    }
                    else
                    {
                        if (i % 2 == 1)
                        {
                            swap(v[i], v[i + 1]);
                        }
                        cout << v[i] << " ";
                    }
                }
                cout << v[v.size() - 1];
            }
            else
            {
                for (int i = 0; i < v.size(); i++)
                {
                    if (i % 2 == 0)
                    {
                        swap(v[i], v[i + 1]);
                    }
                    cout << v[i] << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}