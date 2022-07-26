#include<bits/stdc++.h>
using namespace std;

const int mx=2000;
char adj[mx][mx];
bool vis[mx][mx];
int m,n;
bool flag1=0,flag2=0;

int dx[]={-1,-1,-1,1,1,1,0,0};
int dy[]={1,0,-1,1,0,-1,1,-1};

void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];

        if(x1>=1 && x1<=n && y1>=1 && y1<=n && !vis[x1][y1])
        {
            dfs(x1,y1);
        }
    }
}

int main()
{
    cin>>n;
    int ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            adj[i][j]='.';
            if(i==ax && j==ay)
            {
                adj[i][j]='A';
            }

            if(i==bx && j==by)
            {
                adj[i][j]='B';
            }

            if(i==cx && j==cy)
            {
                adj[i][j]='C';
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        vis[ax][i]=1;
        vis[i][ay]=1;
    }

    for(int i=1;i<=n;i++)
    {
        int j=i+ay-ax;
        if(j>=1 && j<=n)
        {
            vis[i][j]=1;
        }
        j=ay+ax-i;
        if(j>=1 && j<=n)
        {
            vis[i][j]=1;
        }
    }


    dfs(bx,by);
    if(vis[cx][cy])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}