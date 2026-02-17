// Given an array of size N, Find the min length of the subarray that contains both min and maximum.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int minm = *min_element(arr, arr + n);
    int maxm = *max_element(arr, arr + n);
    int ans = n;
    int minIndex = -1, maxIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == minm)
        {
            minIndex = i;
            if (maxIndex != -1)
            {
                ans = min(ans, abs(maxIndex - minIndex) + 1);
            }
        }
        if (arr[i] == maxm)
        {
            maxIndex = i;
            if (minIndex != -1)
            {
                ans = min(ans, abs(maxIndex - minIndex) + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}