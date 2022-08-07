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
        int arr[n];
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr[i] = a;
            if (i > 0)
            {
                if (arr[i] % arr[0] != 0)
                {
                    flag = 1;
                }
            }
        }

        if (flag == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}