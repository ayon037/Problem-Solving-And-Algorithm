#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit | ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
#define infinity 1 << 30
typedef long double Tf;
const Tf EPS = 1e-9;

int main()
{
    Charpoka;
    int n;
    cin>>n;
    vector<int>v;
    int tot=0;
    while(n--)
    {
        int a;
        cin>>a;
        v.pb(a);
        tot+=a;
    }
    sort(v.begin(),v.end());
    int sum=0;
    if(v.size()%2==0)
    {
        
        for(int i=0;i<(v.size()/2);i++)
        {
            sum+=v[i];
        }
    }
    else
    {
        for(int i=0;i<(v.size()/2)+1;i++)
        {
            sum+=v[i];
        }
    }
    cout<<tot-sum<<endl;
    return 0;
}

/*

Steps to Compile cpp file
1. Go To Terminal and click Run Build Task
2. Click C/C++: g++.exe build active file
3. On Terminal, write .\File_Name
4. Write test cases and see the outputs

*/