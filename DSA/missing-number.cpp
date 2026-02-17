#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans = 0;
    vector<long long> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        ans ^= arr[i];
        ans ^= (i + 1);
    }
    cout << ans << endl;
    return 0;
}
