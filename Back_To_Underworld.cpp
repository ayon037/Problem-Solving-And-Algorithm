#include <bits/stdc++.h>
using namespace std;

// Lichen and Vampire Fighting Problem


#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit | ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
//#define mx 100001
#define infinity 1 << 30

const int mx=2e4+123;
bool vis[mx];
vector<int>adj[mx];
int cnt,cnt1;
bool isNode[mx];

void dfs(int u,int col)
{
    vis[u]=1;
    if(col==1)
    {
        cnt1++; // vampire kotogula ache ekta connected component er moddhe sheta count korar jonno
    }
    cnt++; // vampire and lichen kotogula ache ekta connected component er moddhe sheta count korar jonno

    int tmp;
    if(col==1)
    {
        tmp=2;
    }
    else
    {
        tmp=1;
    }
    
    for(auto v: adj[u])
    {
        if(vis[v]==0)
        {
            dfs(v,tmp);
        }
    }
    return;
}

int main()
{
    Charpoka;
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        for(int i=0;i<mx;i++)
        {
            adj[i].clear();
            isNode[i]=0;
            vis[i]=0;
        }
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
            isNode[u]=1;
            isNode[v]=1;
        }

        int ans=0;
        for(int i=1;i<=2e4;i++)
        {
            if(isNode[i]==1 && vis[i]==0)
            {
                cnt=0;
                cnt1=0;
                dfs(i,1);

                ans+=max(cnt1,cnt-cnt1);
                ///cnt1 = vampire er color
                ///cnt-cnt1 = lichen er color
            }
        }

        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}