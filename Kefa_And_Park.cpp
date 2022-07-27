#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 123;
vector<int> adj[mx];
int v[mx];
bool vis[mx];
int m, n;
int rest_count = 0;

bool check(int u)
{
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (vis[adj[u][i]] == 0)
            return 0;
    }
    return 1;
}

void dfs(int u, int y, int cat_count)
{

    if (cat_count > m)
    {
        return;
    }
    if (check(u))
    {
        rest_count++;
        return;
    }

    vis[u] = 1;
    // cout << "Node -> " << u << ": Cat Counted = " << cat_count << " , Resturant Counted = " << rest_count << endl;
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (vis[adj[u][i]] == 0)
        {
            if (v[adj[u][i]] == 1)
            {
                // cat_count++;
                dfs(adj[u][i], 1, cat_count + 1);
            }
            else
            {
                // cat_count = 0;
                dfs(adj[u][i], 1, 0);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= mx; i++)
    {
        adj[i].clear();
        v[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        v[i] = val;
        // cout<<v[i]<<" ";
    }
    // cout<<endl;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        // cout<<i<<"-> "<<a<<": "<<adj[a][0].second<<endl;
        // cout<<i<<"-> "<<b<<": "<<adj[b][0].second<<endl;
    }

    dfs(1, 1, v[1]);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"Node -> "<<i<<": "<<vis[i]<<endl;
    // }
    cout << rest_count;

    return 0;
}