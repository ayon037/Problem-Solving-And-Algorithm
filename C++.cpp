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
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll cnt=0;
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mp.size()==4)
            {
                cnt++;
                mp.clear();
                mp[s[i]]++;
            }
            
        }
        if(mp.size()>=1)
        {
            cnt++;
        }
        cout<<cnt<<endl;
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