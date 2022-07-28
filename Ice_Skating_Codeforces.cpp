#include <bits/stdc++.h>
using namespace std;

const int mx = 5500;
int adj[mx][3];
bool vis[mx];
map<int, bool> mp;
int n, m;

void dfs(int point)
{
    vis[point] = 1;
    for (int i = 1; i <= n; i++)
    {
        if ((adj[i][1] == adj[point][1] || adj[i][2] == adj[point][2]) && vis[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> adj[i][1] >> adj[i][2];
    }
    memset(vis, 0, sizeof(vis));
    int count = -1;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
            count++;
        }
    }
    cout << count << endl;
    return 0;

    return 0;
}