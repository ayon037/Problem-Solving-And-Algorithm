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
    int n;
    cin >> n;
    if (n % 2 == 1) {
        for(int i=1;i<=n-2;i+=2)
        {
            if(i==1)
            {
                cout<<i<<' '<<i+2<<' ';
            }
            else
            {
                if(i==n-2)
                {
                    cout<<i-1<<' ';
                }
                else
                {
                    cout<<i-1<<' '<<i+2<<' ';
                }
            }
            
        }
        cout<<n-1<<' '<<n;
      
    } else {
      for (int i = 1; i <= n - 2; i += 2) {
        cout << i + 1 << ' ' << i << ' ';
      }
      cout << n - 1 << " " << n;
    }
    cout << endl;
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