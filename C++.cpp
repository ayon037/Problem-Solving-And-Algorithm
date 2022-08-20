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
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        ll prod = k * b;
        if (s == prod)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i == 1)
                {
                    cout << prod << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
        }
        else if (s < prod)
        {
            cout << -1;
        }
        else
        {
            if (b == 0 || k == 0)
            {
                if (s == 0)
                {
                    for (int i = 1; i <= n; i++)
                    {
                        cout << 0 << " ";
                    }
                }
                else
                {
                    if (s < k)
                    {
                        for (int i = 1; i <= n; i++)
                        {
                            if (i == 1)
                            {
                                cout << s << " ";
                            }
                            else
                            {
                                cout << 0 << " ";
                            }
                        }
                    }
                    else if (s == k)
                    {
                        if (n - 1 > 0)
                        {
                            for (int i = 1; i <= n; i++)
                            {
                                if (i == 1)
                                {
                                    cout << k - 1 << " ";
                                }
                                else if (i == n)
                                {
                                    cout << 1 << " ";
                                }
                                else
                                {
                                    cout << 0 << " ";
                                }
                            }
                        }
                    }
                    else
                    {
                        if (s > (k - 1) * n)
                        {
                            cout << -1;
                        }
                        else
                        {
                            ll sum = 0;
                            bool flag = 0;
                            for (int i = 1; i <= n; i++)
                            {
                                sum += (k - 1);
                                if (sum < s && flag == 0)
                                {
                                    cout << k - 1 << " ";
                                }
                                else if (sum == s && flag == 0)
                                {
                                    cout << k - 1 << " ";
                                    flag = 1;
                                }
                                else if (sum > s && flag == 0)
                                {
                                    sum -= (k - 1);
                                    cout << s - sum << " ";
                                    flag = 1;
                                }
                                else
                                {
                                    cout << 0 << " ";
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                ll val = prod + (k - 1);
                ll max_sum = (k - 1) * (n - 1);
                if (s > (val + max_sum))
                {
                    cout << -1;
                }
                else
                {
                    ll peak = prod + (k - 1) * (n - 1);
                    if (s <= peak)
                    {
                        ll left = s - prod;
                        ll sum = 0;
                        bool flag = 0;
                        for (int i = 1; i <= n; i++)
                        {
                            if (i == 1)
                            {
                                cout << prod << " ";
                            }
                            else
                            {
                                sum += (k - 1);
                                if (sum < left && flag == 0)
                                {
                                    cout << k - 1 << " ";
                                }
                                else if (sum == left && flag == 0)
                                {
                                    cout << k - 1 << " ";
                                    flag = 1;
                                }
                                else if (sum > left && flag == 0)
                                {
                                    sum -= (k - 1);
                                    cout << left - sum << " ";
                                    flag = 1;
                                }
                                else
                                {
                                    cout << 0 << " ";
                                }
                            }
                        }
                    }
                    else
                    {
                        ll sum = 0;
                        bool flag = 0;
                        ll left = s - val;
                        for (int i = 1; i <= n; i++)
                        {
                            if (i == 1)
                            {
                                cout << val << " ";
                            }
                            else
                            {
                                sum += (k - 1);
                                if (sum < left && flag == 0)
                                {
                                    cout << k - 1 << " ";
                                }
                                else if (sum == left && flag == 0)
                                {
                                    cout << k - 1 << " ";
                                    flag = 1;
                                }
                                else if (sum > left && flag == 0)
                                {
                                    sum -= (k - 1);
                                    cout << left - sum << " ";
                                    flag = 1;
                                }
                                else
                                {
                                    cout << 0 << " ";
                                }
                            }
                        }
                    }
                }
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