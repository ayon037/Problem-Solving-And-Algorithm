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

int Prime[2000];

void Find_Prime(int high)
{
    for (int i = 2; i <= high; i++)
    {
        if (Prime[i] == 0)
        {
            for (int j = i * i; j <= high; j += i)
            {
                Prime[j] = 1;
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    memset(Prime, 0, sizeof(Prime));
    Find_Prime(n);

    int cnt = 0, flag = 0;
    for (int i = 2; i <= n; i++)
    {
        int p = 0, sum = 0;
        if (Prime[i] == 0)
        {
            // cout << i << " ";
            for (int j = 2; j <= n; j++)
            {
                if (Prime[j] == 0)
                {
                    // cout << "(I , J) = "
                    //      << "(" << i << " , " << j << ")"
                    //      << " , ";
                    p++;
                    sum += j;
                    // cout << sum << " , " << p << endl;
                    if (p == 2)
                    {
                        // cout << "I = " << i << ", Sum = " << sum + 1 << ", P = " << p << endl;
                        if (sum + 1 == i)
                        {
                            cnt++;
                            break;
                        }
                        else if (sum + 1 > i)
                        {
                            break;
                        }
                        else
                        {
                            p = 1;
                            sum = j;
                        }
                    }
                }
            }
        }
        if (cnt == k)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
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