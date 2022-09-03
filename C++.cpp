#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pb push_back
#define ll long long int
#define infinity 1 << 30
typedef long double Tf;
const Tf EPS = 1e-9;
const ll MX = 1e5 + 123;
int main() {
  Charpoka;
  int t;
  cin >> t;
  while (t--) 
  {
      int n, m, sx, sy, d;
      cin >> n >> m >> sx >> sy >> d;
      if (sx - d > 1 && sy + d < m) 
      {
          cout << n + m - 2 << endl;
      }   
      else if (sy - d > 1 && sx + d < n) 
      {
          cout << n + m - 2 << endl;
      } 
      else 
      {
          cout << -1 << endl;
      }
  }
  return 0;
}
/*

Steps to Compile cpp file
1. Go To Terminal and click Run Build Task
2. Click C/C++: g++.exe build active file
3. On Terminal, write .\File_Name
4. Write test cases and see the outputs

*/