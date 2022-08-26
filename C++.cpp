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
    int n, m;
    cin >> n >> m;
    int pos = 0;
    int mx = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (m < a)
        {
            if(a%m==0)
            {
                a=a/m;
            }
            else
            {
                a=(a/m)+1;
            }
            //cout<<a<<" = After Ceiling "<<i<<endl;
            if (a >= mx)
            {
                //cout<<a<<" = Hello "<<i<<endl;
                mx = a;
                pos = i;
            }
        }
    }
    if(pos==0)
    {
        cout<<n;
    }
    else
    {
        cout<<pos;
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