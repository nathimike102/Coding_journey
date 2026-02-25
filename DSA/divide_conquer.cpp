#include <bits/stdc++.h>
using namespace std;

void printSubseqRecursion(vector<int> &arr, vector<int> &sq, int index, int n)
{
    if (index == n)
    {
        for (auto it : sq)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // pick
    sq.push_back(arr[index]);
    printSubseqRecursion(arr, sq, index + 1, n);
    // not pick
    sq.pop_back();
    printSubseqRecursion(arr, sq, index + 1, n);
}

void printSubseqBitMask(vector<int> &arr, int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((1 << j) & i)
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n), sq;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        printSubseqRecursion(arr, sq, 0, n);
        printSubseqBitMask(arr, n);
    }
}