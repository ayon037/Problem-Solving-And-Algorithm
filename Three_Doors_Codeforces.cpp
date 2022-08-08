#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int arr[4], key;
        cin >> key;
        cin >> arr[1] >> arr[2] >> arr[3];
        if (arr[1] == 0)
        {
            if (key == 1)
                cout << "NO" << endl;
            else
            {
                if (arr[2] != 2 && arr[3] != 3)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
        else if (arr[2] == 0)
        {
            if (key == 2)
                cout << "NO" << endl;
            else
            {
                if (arr[1] != 1 && arr[3] != 3)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
        else
        {
            if (key == 3)
                cout << "NO" << endl;
            else
            {
                if (arr[1] != 1 && arr[2] != 2)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}