#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s;
        cin >> s;
        map<int, bool> mp;
        string str = "";
        int sum = 0, num = s;
        vector<int> v;
        for (int i = 9; i >= 1; i--)
        {
            if (sum <= num && mp[i] == false && s >= i)
            {
                sum += i;
                s = s - i;
                mp[i] = true;
                v.push_back(i);
            }
            if (sum == num)
            {
                break;
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}