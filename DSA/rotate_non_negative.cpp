#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rotateElements(vector<int> &nums, int k)
    {
        vector<int> nonNegative;
        vector<int> nonNegIndices;

        // Extract non-negative elements and their indices
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                nonNegative.push_back(nums[i]);
                nonNegIndices.push_back(i);
            }
        }

        // If no non-negative elements, return original array
        if (nonNegative.empty())
        {
            return nums;
        }

        // Normalize k to avoid unnecessary rotations
        int n = nonNegative.size();
        if (n > 0)
        {
            k = k % n;

            // Rotate left by k positions
            if (k > 0)
            {
                rotate(nonNegative.begin(), nonNegative.begin() + k, nonNegative.end());
            }
        }

        // Place rotated elements back into original indices
        for (int i = 0; i < nonNegIndices.size(); i++)
        {
            nums[nonNegIndices[i]] = nonNegative[i];
        }

        return nums;
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, -2, 3, -4};
    int k1 = 3;
    vector<int> result1 = sol.rotateElements(nums1, k1);
    cout << "Example 1: ";
    for (int x : result1)
        cout << x << " ";
    cout << "\n"; // Expected: [3, -2, 1, -4]

    // Example 2
    vector<int> nums2 = {-3, -2, 7};
    int k2 = 1;
    vector<int> result2 = sol.rotateElements(nums2, k2);
    cout << "Example 2: ";
    for (int x : result2)
        cout << x << " ";
    cout << "\n"; // Expected: [-3, -2, 7]

    // Example 3 - Failing test case
    vector<int> nums3 = {-20, -13, 0, 24};
    int k3 = 76135;
    vector<int> result3 = sol.rotateElements(nums3, k3);
    cout << "Example 3: ";
    for (int x : result3)
        cout << x << " ";
    cout << "\n"; // Expected: [-20, -13, 24, 0]

    return 0;
}
