#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minLengthAfterRemovingPrefix(vector<int> &nums)
    {
        int n = nums.size();

        // Work backwards: find the rightmost strictly increasing suffix
        // Start from the end and work backwards checking strictly increasing property
        int validStart = n - 1; // Initially, the last element is valid

        for (int i = n - 2; i >= 0; i--)
        {
            // If nums[i] < nums[i+1], this element can be included in the suffix
            if (nums[i] < nums[i + 1])
            {
                validStart = i;
            }
            else
            {
                // Once we break the strictly increasing property, stop
                break;
            }
        }

        return validStart; // Return the number of elements to remove (prefix length)
    }
};

int main()
{
    // Test case 1
    vector<int> nums1 = {1, -1, 2, 3, 1, 4, 5};
    Solution sol;
    cout << "Test 1: " << sol.minLengthAfterRemovingPrefix(nums1) << " (Expected: 4)" << endl;

    // Test case 2
    vector<int> nums2 = {4, 3, -2, -5};
    cout << "Test 2: " << sol.minLengthAfterRemovingPrefix(nums2) << " (Expected: 3)" << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 4};
    cout << "Test 3: " << sol.minLengthAfterRemovingPrefix(nums3) << " (Expected: 0)" << endl;

    return 0;
}
