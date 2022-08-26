#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
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
    int t;
    cin >> t;
    while (t--)
    {
        int arr[2][2];
        int cnt = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        if (cnt == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            if (cnt == 1)
            {
                cout << 1 << endl;
            }
            else if (cnt == 2)
            {
                cout << 1 << endl;
            }
            else if (cnt == 3)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
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