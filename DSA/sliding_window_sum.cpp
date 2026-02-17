/*
You are given an array of 𝑛 integers. Your task is to calculate the sum of each window of
𝑘 elements, from left to right.
In this problem the input data is large and it is created using a generator.

Input
The first line contains two integers n and k: the number of elements and the size of the window.
The next line contains four integers
𝑥, a, b and 𝑐: the input generator parameters. The input is generated as follows:

Output
Print the xor of all window sums.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
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
    for (int i = 0; i < k; i++)
    {
        curr += arr[i];
    }
    for (int i = k; i < n; i++)
    {
        res ^= curr;
        curr -= arr[i - k];
        curr += arr[i];
    }
    res ^= curr;
    cout << res << endl;
    return 0;
}