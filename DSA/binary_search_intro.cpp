/*
Binary Search
== == == == == ==

    Binary search is a searching algorithm that works on sorted arrays. It repeatedly divides the search interval in half until the target value is found or the search interval is empty
    Time Complexity: O(log n)
    Space Complexity: O(1) for iterative version, O(log n) for recursive version due to call stack

    Steps:
    1. Start with two pointers, one at the beginning of the array (left) and one at the end of the array (right).
    2. Calculate the middle index: mid = left + (right - left) / 2
    3. Compare the target value with the middle element of the array:
       - If they are equal, return the middle index.
       - If the target value is less than the middle element, move the right pointer to mid - 1 (search in the left half).
       - If the target value is greater than the middle element, move the left pointer to mid + 1 (search in the right half).
    4. Repeat steps 2 and 3 until the target value is found or the left pointer exceeds the right pointer (indicating that the target value is not in the array).

Rotated sorted array:
A sorted array that has been rotated at some pivot point.
For example, [4, 5, 6, 7, 0, 1, 2] is a rotated sorted array.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            cout << "Element found at index: " << mid << endl;
            return 0;
        }
        // left half is sorted
        else if (arr[mid] > arr[left])
        {
            if (target >= arr[left] && target < arr[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        // right half is sorted
        else
        {
            if (target > arr[mid] && target <= arr[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    cout << "Element not found in the array." << endl;
    return 0;
}
