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
    int n,k;
    cin>>n>>k;
    vector< pair<int,int> >v;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        v.pb({a,i});
    }
    int sum=0;
    sort(v.begin(),v.end());
    int i=0;
    vector<int>select;
    while(i<v.size())
    {
        sum+=v[i].first;
        if(sum<=k)
        {
            int num=v[i].second;
            select.pb(num);
        }
        else
        {
            break;
        }
        i++;
    }
   
    cout<<select.size()<<endl;
    for(int j=0;j<select.size();j++)
    {
        cout<<select[j]<<" ";
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