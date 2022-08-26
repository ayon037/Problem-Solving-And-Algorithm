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
    int n;
    cin >> n;
    char board[n][n];
    bool even = true;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (i - 1 >= 0 and board[i - 1][j] == 'o')
                c++;
            if (i + 1 < n and board[i + 1][j] == 'o')
                c++;
            if(j - 1 >= 0 and board[i][j - 1] == 'o')
                c++;
            if(j + 1 < n and board[i][j + 1] == 'o')
                c++;
            if (c % 2 == 1)
                even = false;
        }
    }

    if (even)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

/*

Steps to Compile cpp file
1. Go To Terminal and click Run Build Task
2. Click C/C++: g++.exe build active file
3. On Terminal, write .\File_Name
4. Write test cases and see the outputs

*/