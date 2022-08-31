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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll sum=0;
        vector<ll>v;
        for(ll i=0;i<s.size();i++)
        {
            if(s[i]=='L')
            {
                sum+=i;
                v.pb(n-i-1-i);
            }
            else
            {
                sum+=(n-i-1);
                v.pb(i-(n-i-1));
            }
        }
        sort(v.rbegin(),v.rend());
        for(ll k=0;k<n;k++)
        {
            if(v[k]>0)
            {
                sum+=v[k];
            }
            cout<<sum<<" ";
        }
        cout<<endl;

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