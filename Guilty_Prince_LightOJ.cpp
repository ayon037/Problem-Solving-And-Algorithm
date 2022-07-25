#include<bits/stdc++.h>
using namespace std;
const int mx=30;
bool vis[mx][mx];
vector<char>adj[mx];
int cnt=0;
char c[mx][mx];
int m,n;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x,int y)
{
    vis[x][y]=1;
    cnt++;
    for(int i=0;i<4;i++)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];

        if(x1>=1 && x1<=n && y1>=1 && y1<=m && !vis[x1][y1] && c[x1][y1]!='#')
        {
            dfs(x1,y1);
        }
    }

}

int main()
{
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++)
    {

        memset(vis,0,sizeof(vis));
        cnt=0;
        int x,y;
        cin>>m>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j]; 
                if(c[i][j]=='@')
                {
                    x=i;
                    y=j;
                }
            }
        }

        dfs(x,y);

        cout<<"Case "<<tc<<": "<<cnt<<endl;
    }   
    return 0;
}