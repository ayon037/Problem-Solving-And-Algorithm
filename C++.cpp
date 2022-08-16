#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit | ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
#define infinity 1 << 30
typedef long double Tf;
const Tf EPS = 1e-9;

int main()
{
    Charpoka;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<char, int> mp;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            char ch;
            cin >> ch;
            mp[ch]++;
            if (mp[ch] == 1)
            {
                cnt += 2;
            }
            else
            {
                cnt++;
            }
        }
        cout << cnt << endl;
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