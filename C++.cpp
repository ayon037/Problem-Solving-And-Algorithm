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
        int n;
        cin >> n;
        map<string, int> mp;
        vector<string> v1, v2, v3;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            mp[s]++;
            v1.push_back(s);
        }
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            mp[s]++;
            v2.push_back(s);
        }
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            mp[s]++;
            v3.push_back(s);
            if (mp[s] == 1)
            {
                cnt3 += 3;
            }
            else if (mp[s] == 2)
            {
                cnt3 += 1;
            }
        }

        for (int i = 0; i < v1.size(); i++)
        {
            if (mp[v1[i]] == 1)
            {
                cnt1 += 3;
            }
            else if (mp[v1[i]] == 2)
            {
                cnt1 += 1;
            }
        }
        for (int i = 0; i < v2.size(); i++)
        {
            if (mp[v2[i]] == 1)
            {
                cnt2 += 3;
            }
            else if (mp[v2[i]] == 2)
            {
                cnt2 += 1;
            }
        }
        cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
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