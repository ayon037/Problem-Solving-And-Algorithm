#include <bits/stdc++.h>
using namespace std;

const int mx = 1000;
bool vis[mx];
vector<int> adj[mx];
int cnt;

void dfs(int u)
{
    vis[u] = true;
    cnt++;
    for (auto v : adj[u])
    {
        if (vis[v] == false)
        {
            dfs(v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            cnt = 0;
            dfs(i);
            ans = max(ans, cnt);
        }
    }

    cout << ans;
    return 0;
}