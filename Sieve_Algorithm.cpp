#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit | ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
#define infinity 1 << 30
typedef long double Tf;
const Tf EPS = 1e-9;

long long int Find_Prime(long long int low, long long int high)
{
    long long int MX = 1e6 + 123;
    long long int Prime[MX] = {0};
    long long int cnt = 0;
    for (long long int i = 2; i <= high; i++)
    {
        if (Prime[i] == 0)
        {
            for (long long int j = i * i; j <= high; j += i)
            {
                // cout << j << " ";
                Prime[j] = 1;
            }
        }
    }
    if (low == 1)
    {
        for (long long int i = 2; i <= high; i++)
        {
            if (Prime[i] == 0)
            {
                cnt++;
            }
        }
    }
    else
    {
        for (long long int i = low; i <= high; i++)
        {
            if (Prime[i] == 0)
            {
                cnt++;
            }
        }
    }
    // cout << endl;
    return cnt;
}
int main()
{
    Charpoka;
    int t;
    cin >> t;
    while (t--)
    {
        long long int low, high;
        cin >> low >> high;
        long long int ans = Find_Prime(low, high);
        cout << ans << endl;
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