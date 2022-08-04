#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 3 == 0)
        {
            cout << n / 3 << endl;
        }
        else if (n % 3 == 1)
        {
            // if(n%2==0)
            // {
            //     int val1=(n/3)+2;
            //     int val2=((n/3)-1);
            //     int val3=val2+(n-(3*val2))/2;
            //     cout<<min(val1,val3)<<endl;
            // }
            // else
            // {
            //     int val1=(n/3)+2;
            //     int val2=((n/3)-1);
            //     int val3=val2+(n-(3*val2))/2;
            //     cout<<min(val1,val3)<<endl;
            // }
            if (n == 1)
            {
                cout << 2 << endl;
            }
            else
            {
                int val1 = (n / 3) + 2;
                int val2 = ((n / 3) - 1);
                int val4 = n - (3 * val2);
                if (val4 % 2 == 0)
                {
                    cout << val2 + val4 / 2 << endl;
                }
                else
                {
                    cout << val1 << endl;
                }
            }
        }
        else
        {
            int ans1 = (n / 3) + ((n - (3 * (n / 3))) / 2);
            int ans2 = n / 2;
            cout << min(ans1, ans2) << endl;
        }
    }
    return 0;
}