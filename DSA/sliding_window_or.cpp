/*
You are given an array of n integers. Your task is to calculate the bitwise or of each window of k elements, from left to right.
In this problem the input data is large and it is created using a generator.

Input
The first line contains two integers
n and
k: the number of elements and the size of the window.

The next line contains four integers
x, a, b and c: the input generator parameters. The input is generated as follows:
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<long long> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++)
    {
        arr[i] = (arr[i - 1] * a + b) % c;
    }
    long long res = 0;
    long long curr = 0;
    vector<long long> win(32, 0);
    for (int i = 0; i < k; i++)
    {
        curr |= arr[i];
        bitset<sizeof(unsigned long) * CHAR_BIT> bits(arr[i]);
        for (int i = 0; i < bits.size(); ++i)
        {
            if (bits.test(i))
            {
                win[i]++;
            }
        }
    }
    res ^= curr;
    for (int i = k; i < n; i++)
    {
        bitset<sizeof(unsigned long) * CHAR_BIT> bits_remove(arr[i - k]);
        for (int j = 0; j < bits_remove.size(); ++j)
        {
            if (bits_remove.test(j))
            {
                win[j]--;
            }
        }
        bitset<sizeof(unsigned long) * CHAR_BIT> bits_add(arr[i]);
        for (int j = 0; j < bits_add.size(); ++j)
        {
            if (bits_add.test(j))
            {
                win[j]++;
            }
        }
        curr = 0;
        for (int j = 0; j < win.size(); ++j)
        {
            if (win[j] > 0)
            {
                curr |= (1LL << j);
            }
        }
        res ^= curr;
    }
    cout << res;
    return 0;
}