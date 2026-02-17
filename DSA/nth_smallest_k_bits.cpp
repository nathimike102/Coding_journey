#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long nthSmallest(long long n, int k)
    {
        // Start with the smallest number with k bits set
        // This is k consecutive 1s from the right: (1 << k) - 1
        long long num = (1LL << k) - 1;

        // Generate the nth number with exactly k set bits
        for (long long i = 1; i < n; i++)
        {
            // Find next number with same number of set bits
            // Using Gosper's hack / next bit permutation
            long long c = num & -num; // rightmost set bit
            long long r = num + c;    // flip the rightmost block of 1s
            // Move the remaining 1s to the rightmost positions
            num = (((r ^ num) >> 2) / c) | r;
        }

        return num;
    }
};

int main()
{
    Solution sol;

    // Example 1: n = 4, k = 2
    long long result1 = sol.nthSmallest(4, 2);
    cout << "Example 1: " << result1 << " (Expected: 9)\n";
    // Numbers with 2 bits: 3 (11), 5 (101), 6 (110), 9 (1001)

    // Example 2: n = 3, k = 1
    long long result2 = sol.nthSmallest(3, 1);
    cout << "Example 2: " << result2 << " (Expected: 4)\n";
    // Numbers with 1 bit: 1 (1), 2 (10), 4 (100)

    // Additional test
    long long result3 = sol.nthSmallest(1, 2);
    cout << "Additional test: " << result3 << " (Expected: 3)\n";

    return 0;
}
