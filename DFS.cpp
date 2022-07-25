#include<bits/stdc++.h>
using namespace std;
const int mx=112;
bool vis[mx];
vector<int>adj[mx];

void dfs(int u)
{
    vis[u]=1;
    for(auto v:adj[u])
    {
        if(vis[v]==0)
        {
            dfs(v);
        }
    }
}

int main()
{
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[3].push_back(3);

    dfs(1);

    return 0;
}