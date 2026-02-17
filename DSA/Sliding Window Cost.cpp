//https://cses.fi/problemset/task/1077
#include <iostream>
#include <set>
#include<vector>
using namespace std;
 
#define int long long
 
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto &i : nums)
    {
        cin >> i;
    }
 
    vector<int> ans;
 
    multiset<int> lo, hi;
    int losum = 0, hisum = 0;
    auto balance = [&]()
    {
        if (lo.size() > hi.size() + 1)
        {
            hisum += *lo.rbegin();
            losum -= *lo.rbegin();
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
        }
        if (hi.size() > lo.size())
        {
            hisum -= *hi.begin();
            losum += *hi.begin();
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    };
 
    for (int i = 0; i < n; i++)
    {
 
        if (lo.empty() || nums[i] <= *lo.rbegin())
        {
            lo.insert(nums[i]);
            losum += nums[i];
        }
        else
        {
            hi.insert(nums[i]);
            hisum += nums[i];
        }
 
        balance();
 
        if (i >= k)
        {
            int out = nums[i - k];
            if (out <= *lo.rbegin())
            {
                losum -= out;
                lo.erase(lo.find(out));
            }
            else
            {
                hisum -= out;
                hi.erase(hi.find(out));
            }
            balance();
        }
 
        if (i >= k - 1)
        {
            int median = *lo.rbegin();
            int val = ((median * lo.size()) - losum) + (hisum - (hi.size() * median));
            ans.push_back(val);
        }
    }
 
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
 
    return 0;
}
