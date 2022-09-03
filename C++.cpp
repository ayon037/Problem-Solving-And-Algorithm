#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pb push_back
#define ll long long int
#define infinity 1 << 30
typedef long double Tf;
const Tf EPS = 1e-9;
const int MX = 1e5 + 123;
int cnt;

void bfs(int s, string str,map<int,vector<int> >&adj,int visited[],set<string> &p) {
  queue<int> Q;
  Q.push(s);
  visited[s] = 1;
  // p.push_back(sq);
  string sq = "";

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if (adj[u].size() != 0) {
      sq += str[u - 1];
      p.insert(sq);
      string sr1 = sq;
      reverse(sr1.begin(), sr1.end());
      //cout << it << " ";
      if (sr1 == sq) {
        cnt++;
      }

    }

    for (int i = 0; i < adj[u].size(); i++) {
      if (visited[adj[u][i]] == 0) {
        int v = adj[u][i];
        visited[v] = 1;
        Q.push(v);
        sq += str[v - 1];
        p.insert(sq);
        sq.erase(sq.size() - 1);
        string sr1 = sq;
      reverse(sr1.begin(), sr1.end());
      //cout << it << " ";
      if (sr1 == sq) {
        cnt++;
      }
      }
    }
  }
}

int main() {
  Charpoka;
  int t;
  cin >> t;
  int y=0;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // memset(adj,-1,sizeof(adj));
    map<int, vector<int>> adj;
    int visited[MX];


    // adj.clear();
    // memset(visited, 0, sizeof(visited));
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      // adj[v].push_back(u);
    }
    cnt=0;
    set<string> p;

    bfs(1, s,adj,visited,p);
    //cout << p.size() << endl;
    // set<string>::iterator it;
    //int cnt = 0;
    
    //cout << endl;
    if(n>1)
    {
        cout<<"Case "<<++y<<": "<<cnt<<"/"<<p.size()<<endl;
    }
    else
    {
        cout<<"Case "<<++y<<": "<<1<<"/"<<1<<endl;
    }
    p.clear();
    
  }
}
/*

Steps to Compile cpp file
1. Go To Terminal and click Run Build Task
2. Click C/C++: g++.exe build active file
3. On Terminal, write .\File_Name
4. Write test cases and see the outputs

*/