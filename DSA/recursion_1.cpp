/*
Given an integer of size N and given an integer B, find all index where B present. (Recursion)
A = [1, 5, 4, 5, 3, 2, 5]
     0  1  2  3  4  5  6
B = 5
o/p = [1, 3, 6]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> my_recursion(vector<int> arr, vector<int> &ans, int index, int b, int n)
{
    if (index == n)
        return ans;
    if (arr[index] == b)
    {
        ans.push_back(index);
    }
    return my_recursion(arr, ans, index + 1, b, n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int b;
    cin >> b;
    vector<int> ans;
    ans = my_recursion(arr, ans, 0, b, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}