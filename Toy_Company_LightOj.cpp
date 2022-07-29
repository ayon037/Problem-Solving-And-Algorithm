#include <bits/stdc++.h>
using namespace std;

map<string, bool> vis;
set<string> s;
string start, finish;

int bfs()
{
    queue<string> q;
    q.push(start);
    int level = 0;
    while (!q.empty())
    {
        level++;
        int sz = q.size();
        while (sz--)
        {
            string x = q.front();
            q.pop();
            vis[x] = 1;
            for (int i = 0; i < x.size(); i++)
            {
                string t1 = x, t2 = x;
                t1[i] = (char)(x[i] - 'a' + 1) % 26 + 'a';
                t2[i] = (char)(x[i] - 'a' - 1 + 26) % 26 + 'a';
                if (s.find(x) != s.end())
                {
                    continue;
                }
                if ((s.find(t1) == s.end() && t1 == finish) || (s.find(t2) == s.end() && t2 == finish))
                {
                    return level;
                }
                if (s.find(t1) == s.end() && vis[t1] == 0)
                {
                    q.push(t1);
                    vis[t1] = 1;
                }
                if (s.find(t2) == s.end() && vis[t2] == 0)
                {
                    q.push(t2);
                    vis[t2] = 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int t, cnt = 0;
    cin >> t;
    while (t--)
    {
        cin >> start >> finish;
        int n;
        string s1, s2, s3;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> s1 >> s2 >> s3;
            for (int j = 0; j < s1.size(); j++)
            {
                for (int k = 0; k < s2.size(); k++)
                {
                    for (int l = 0; l < s3.size(); l++)
                    {
                        string str = "";
                        str = str + s1[j] + s2[k] + s3[l];
                        s.insert(str);
                    }
                }
            }
        }
        cout << "Case " << ++cnt << ": ";
        if (s.find(finish) != s.end())
        {
            cout << -1 << endl;
        }
        else if (start == finish)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << bfs() << endl;
        }
        s.clear();
        vis.clear();
    }
    return 0;
}