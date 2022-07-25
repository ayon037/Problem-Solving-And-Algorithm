#include <bits/stdc++.h>
using namespace std;
int g[100][100];
int c[100];
int n, maxx;
int safe(int node, int color)
{
    for (int i = 0; i < n; i++)
    {
        if (i != node && g[i][node] == 1 && c[i] == color)
        {
            return 0;
        }
    }
    return 1;
}

int color(int node)
{
    if (n == node)
    {
        return 1;
    }

    for (int i = 1; i <= maxx; i++)
    {
        if (safe(node, i))
        {
            c[node] = i;
            if (color(node + 1))
            {
                return 1;
            }
            c[node] = 0;
        }
    }
    return 0;
}
int main()
{
    int e, a, b;
    cin >> n;
    cin >> e;
    cin >> maxx;
    memset(g, -1, sizeof g);
    memset(c, -1, sizeof c);
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    color(0);
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
}
