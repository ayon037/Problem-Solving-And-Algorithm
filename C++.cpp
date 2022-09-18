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
    ll n,d;
    cin>>n>>d;
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        v.pb(a);
    }
    sort(v.rbegin(),v.rend());
    int cnt=0,select=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>d)
        {
            select++;
            cnt++;
        }
        else
        {
            int div=d/v[i];
            if(v[i]*div<=d)
            {
                div++;
            }
            cnt+=div;
            if(cnt<=v.size())
            {
                select++;
            }
            else
            {
                break;
            }
        }
    }
    cout<<select<<endl;
    return 0;
}
/*

Steps to Compile cpp file
1. Go To Terminal and click Run Build Task
2. Click C/C++: g++.exe build active file
3. On Terminal, write .\File_Name
4. Write test cases and see the outputs

*/