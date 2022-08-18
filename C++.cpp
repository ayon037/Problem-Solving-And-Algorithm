#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit | ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
#define infinity 1 << 30
typedef long double Tf;
const Tf EPS = 1e-9;
const ll MX = 1e5 + 123;

int main()
{
    Charpoka;
    int n;
    cin >> n;
    char arr[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    char c1 = arr[1][1], c2 = arr[1][2];
    int flag = 0, idx = n;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i][i] != c1)
        {
            flag = 1;
            break;
        }
        if (arr[i][n - i + 1] != c1)
        {
            flag = 1;
            break;
        }
        // else
        // {
        //     cout << "(" << i << ", " << i << " )" << arr[i][i] << " "
        //          << "(" << i << ", " << n - i + 1 << " )" << arr[i][n - i + 1] << endl;
        // }
    }
    // cout << "flag = " << flag << endl;
    if (flag == 1)
    {
        cout << "NO";
    }
    else
    {
        if (c2 == c1)
        {
            flag = 1;
        }
        else
        {
            idx = n;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if ((j != i) && j != (n - i + 1))
                    {
                        if (arr[i][j] == c1 || arr[i][j] != c2)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
                if (flag == 1)
                {
                    break;
                }
            }
        }
        if (flag == 1)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
    }
    return 0;
}

/*

Steps to Compile cpp file
1. Go To Terminal and click Run Build Task
2. Click C/C++: g++.exe build active file
3. On Terminal, write .\File_Name
4. Write test cases and see the outputs

*/