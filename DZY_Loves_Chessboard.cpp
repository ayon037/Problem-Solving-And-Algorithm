#include <bits/stdc++.h>
using namespace std;

const int mx = 2000;
char adj[mx][mx];
bool vis[mx][mx];
int m, n;
bool flag1 = 0, flag2 = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    if ((x + y) % 2 == 1 && adj[x][y] == '.')
    {
        adj[x][y] = 'B';
    }
    else if ((x + y) % 2 == 0 && adj[x][y] == '.')
    {
        adj[x][y] = 'W';
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + dx[i];
        int y1 = y + dy[i];

        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && !vis[x1][y1])
        {
            dfs(x1, y1);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> adj[i][j];
        }
    }

    dfs(1, 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << adj[i][j];
        }
        cout << endl;
    }

    return 0;
}