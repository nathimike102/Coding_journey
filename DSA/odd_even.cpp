// Prefix Sum
// Given an array of integers, count the number of subarrays whose sum of odd indices is equal to the sum of even indices after eliminating index i (o-n-1).

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // Prefix sums for even and odd indices
    // left even + right odd
    // left odd + right even
    // compare both, if same count++
    vector<int> evenPrefix(n, 0), oddPrefix(n, 0);
    evenPrefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            evenPrefix[i] = evenPrefix[i - 1] + arr[i];
        }
        else
        {
            evenPrefix[i] = evenPrefix[i - 1];
        }
        if (i % 2 == 1)
        {
            oddPrefix[i] = oddPrefix[i - 1] + arr[i];
        }
        else
        {
            oddPrefix[i] = oddPrefix[i - 1];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int leftEven = (i > 0) ? evenPrefix[i - 1] : 0;
        int leftOdd = (i > 0) ? oddPrefix[i - 1] : 0;
        int rightEven = evenPrefix[n - 1] - evenPrefix[i];
        int rightOdd = oddPrefix[n - 1] - oddPrefix[i];
        if (i % 2 == 0)
        {
            rightEven -= arr[i];
        }
        else
        {
            rightOdd -= arr[i];
        }
        if (leftEven + rightOdd == leftOdd + rightEven)
            count++;
    }
    cout << count << endl;
    return 0;
}