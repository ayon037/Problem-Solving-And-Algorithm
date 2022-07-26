#include <bits/stdc++.h>
using namespace std;

int n;
const int mx = 2000;
vector<int> adj[mx];
bool vis[mx];
int flag;
// map<int,int>mp;
int temp;

void dfs(int u)
{

    vis[u] = 1;
    // int p=v;
    for (auto i : adj[u])
    {
        if (vis[i] == 0)
        {
            dfs(i);
        }
        if (vis[i] == 1)
        {
            flag++;
            if (flag == 1)
            {
                // mp[temp]=i;
                cout << i << " ";
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        adj[i].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        dfs(i);
        temp = i;
        flag = 0;
        // cout<<mp[temp]<<" ";
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}