#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int v[n + 1];
    int max1 = 0, max2 = 0;
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        // if the number is greater than the max of
        // all numbers inserted previously, it is a record
        // and hence is marked 1 and the maximum is updated
        // and previous maximum is also updated
        if (a > max1)
        {
            max2 = max1;
            max1 = a;
            v[max1]--;
        }
        // if the number isnt greater than max of all numbers
        // inserted previous, but is greater than previous max
        // then the current max is done -1, as it is causing
        // hindrance for an element to become a record
        // and we are updating the previous max as well
        else if (a > max2)
        {
            max2 = a;
            v[max1]++;
        }
    }
    int ans = 1;
    // the minimum of all number must be removed
    // at it caused most hindrance in creating other records
    for (int i = 2; i <= n; i++)
    {
        if (v[i] > v[ans])
        {
            ans = i;
        }
    }
    cout << ans;
    return 0;
}