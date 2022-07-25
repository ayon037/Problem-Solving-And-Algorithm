#include<bits/stdc++.h>
using namespace std;

const int mx=1000;
char c[mx][mx];
bool vis[mx][mx];
int m,n;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool flag=0;

void dfs(int x,int y)
{
    vis[x][y]=1;
    if (c[x][y] == 'W')
    {
        if ((x - 1) >= 1 && (x - 1) <= n)
        {
            if (c[x - 1][y] == '.' || c[x - 1][y] == 'D')
            {
                c[x - 1][y] = 'D';
            }
            else if (c[x - 1][y] == 'S')
            {
                flag = 1;
            }
        }

        if ((x + 1) >= 1 && (x + 1) <= n)
        {
            if (c[x + 1][y] == '.' || c[x + 1][y] == 'D')
            {
                c[x + 1][y] = 'D';
            }
            else if (c[x + 1][y] == 'S')
            {
                flag = 1;
            }
        }

        if ((y - 1) >= 1 && (y - 1) <= m)
        {
            if (c[x][y - 1] == '.' || c[x][y - 1] == 'D')
            {
                c[x][y - 1] = 'D';
            }
            else if (c[x][y - 1] == 'S')
            {
                flag = 1;
            }
        }

        if ((y + 1) >= 1 && (y + 1) <= m)
        {
            if (c[x][y + 1] == '.' || c[x][y + 1] == 'D')
            {
                c[x][y + 1] = 'D';
            }
            else if (c[x][y + 1] == 'S')
            {
                flag = 1;
            }
        }
    }
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
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }
    dfs(1, 1);
    if (flag == 0)
    {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << c[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }

    // for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=m;j++)
    //         {
    //             cout<<c[i][j];
    //         }
    //         cout<<endl;
    //     }
    return 0;
}