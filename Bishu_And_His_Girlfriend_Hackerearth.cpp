#include <bits/stdc++.h>
using namespace std;

const int mx = 1e3 + 123;
vector<int> adj[mx];
int lev[mx];

void bfs(int s)
{
    memset(lev, -1, sizeof(lev));

    lev[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (lev[v] == -1)
            {
                lev[v] = lev[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    int q;
    cin >> q;

    int ans = 100000, node = 100000;
    while (q--)
    {
        int u;
        cin >> u;

        if (lev[u] <= ans)
        {
            ans = lev[u];
            node = min(node, u);
        }
    }
    cout << node << endl;

    return 0;
}