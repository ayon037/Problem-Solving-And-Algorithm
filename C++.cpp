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
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v, v2;
        int n, mx = INT_MIN, mn = INT_MAX;
        cin >> n;
        map<int, int> mp;
        int pos;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            mp[a]++;

            if (a > mx)
            {
                pos = i;
            }

            mx = max(mx, a);
            mn = min(mn, a);

            v.push_back(a);
        }
        if (n == 1 || n == 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            int flag = 0;
            for (int i = 0; i < pos; i++)
            {
                if (v[i] > v[i + 1])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                for (int i = pos; i < v.size() - 1; i++)
                {
                    if (v[i] < v[i + 1])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
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