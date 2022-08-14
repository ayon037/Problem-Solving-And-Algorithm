#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, cnt = 0;
    cin >> n;
    while (n >= 1)
    {
        cnt = cnt + n % 2;
        n = n / 2;
    }

    cout << cnt;
    return 0;
}