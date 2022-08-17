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
    int n, f, d;
    cin >> n >> f >> d;
    vector<int> v;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        mp[v[i] % d].push_back(v[i]);
        if (mp[v[i] % d].size() == f)
        {
            flag = 1;
            cout << "Yes" << endl;
            for (int j = 0; j < f; j++)
            {
                cout << mp[v[i] % d][j] << " ";
            }
            break;
        }
    }
    if (flag == 0)
    {
        cout << "No";
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