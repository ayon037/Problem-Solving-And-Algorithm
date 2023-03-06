#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit | ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
#define mx 100001
#define infinity 1 << 30
int main()
{
    Charpoka;
    int t;
    cin>>t;
    int cnt=0;
    while(t--)
    {
        int n;
        cin>>n;
        int n1=n,n2=n;
        vector<int>w,b,diff;
        while(n1--)
        {
            int a;
            cin>>a;
            w.pb(a);
        }
        int i=0;
        while(n2--)
        {
            int a;
            cin>>a;
            b.pb(a);
            diff.pb(a-w[i]);
            i++;
        }
        int Xor=0;
        for(int i=0;i<diff.size();i++)
        {
            Xor ^= (diff[i]-1);
        }
        cout<<"Case "<<++cnt<<": ";

        if(Xor)
            cout<<"white wins"<<endl;
        else
            cout<<"black wins"<<endl;
    }
    return 0;
}