#include <bits/stdc++.h>
using namespace std;

int n;
const int mx = 2e5 + 123;
int adj[mx];
map<int, bool> mp;
bool vis[mx];
set<int> path;

void dfs(int u)
{
    if (u != 1)
    {
        dfs(adj[u]);
    }
    path.insert(u);
    return;
}

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> adj[i];
    }
    dfs(n);
    set<int>::iterator it;
    // cout<<1<<" ";
    for (it = path.begin(); it != path.end(); it++)
    {
        cout << *it << " ";
    }
    // cout<<n;
    return 0;
}