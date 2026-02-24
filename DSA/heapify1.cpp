#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool swapped = true;
    for (int i = 0; i < n; i++)
    {
        int a1 = (i + 1);
        int a2 = arr[i];
        if (a1 != a2)
        {
            while (a1 % 2 == 0)
            {
                a1 /= 2;
            }
            while (a2 % 2 == 0)
            {
                a2 /= 2;
            }
            if (a1 != a2)
            {
                swapped = false;
                break;
            }
        }
    }
    if (swapped)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}