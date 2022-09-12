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
        int n;
        cin>>n;
        string s;
        cin>>s;
        string str="";
        for(int i=0;i<s.size();i++)
        {
            vector<char>v;
            v.pb(s[i]);
            if(i+3<s.size())
            {
                for(int j=i+1;;j++)
                {
                    v.pb(s[j]);
                    v.pb(s[j+1]);
                    v.pb(s[j+2]);
                    break;
                }
                if(v[2]=='0' && v[3]=='0')
                {
                    int num=(int)s[i]-48;
                    str+=(char)num+96;
                }
                else if(v[2]=='0' && v[3]!='0')
                {
                    int num=(int)s[i]-48;
                    int val=(int)s[i+1]-48;
                    num*=10;
                    num+=val;
                    str+=(char)num+96;
                    i+=2;
                }
                else 
                {
                    int num=(int)s[i]-48;
                    str+=(char)num+96;
                }
            }
            else 
            {
                if(i+2<s.size())
                {
                    if(s[i+2]=='0')
                    {
                        int num=(int)s[i]-48;
                        int p=(int)s[i+1]-48;
                        num*=10;
                        num+=p;
                        str+=(char)num+96;
                        i+=2;
                    }
                    else
                    {
                        int num=(int)s[i]-48;
                        str+=(char)num+96;
                    }
                }
                else
                {
                    int num=(int)s[i]-48;
                    str+=(char)num+96;
                }
            }
        }
        cout<<str<<endl;
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