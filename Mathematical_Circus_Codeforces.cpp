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
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k % 4 == 0) {
      cout << "NO" << endl;
    } else {
      if (k % 4 == 1 || k % 4 == 3) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i += 2) {
          cout << i << " " << i + 1 << endl;
        }
      } else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i += 2) {
          if ((i + 1) % 4 == 0) {
            cout << i << " " << i + 1 << endl;
          } else {
            cout << i + 1 << " " << i << endl;
          }
        }
      }
    }
  }
  return 0;
}