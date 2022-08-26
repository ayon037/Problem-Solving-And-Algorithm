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
    while (n--)
    {
        int t;
        cin >> t;
        cout << 2 << endl;
        for (int i = 1; i <= t; i += 2)
        {
            for (int j = i; j <= t; j *= 2)
            {
                cout << j << " ";
            }
        }
        cout << endl;
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