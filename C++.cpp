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
        if(n%4==0)
        {
            for(ll i=0;i<n;i++)
            {
                cout<<i<<" ";
            }
        }
        else if(n%4==1)
        {
            cout<<0<<" ";
            for(int i=0;i<n-1;i++)
            {
                cout<<i+2<<" ";
            }
            
        }
        else if(n%4==2)
        {
            cout<<2<<" "<<3<<" "<<1<<" "<<4<<" "<<12<<" "<<8<<" ";
            for(int i=0;i<n-6;i++)
            {
                cout<<14+i<<" ";
            }
        }
        else
        {
            cout<<2<<" "<<1<<" "<<3<<" ";
            for(int i=0;i<n-3;i++)
            {
                cout<<4+i<<" ";
            }
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