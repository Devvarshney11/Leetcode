#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
// By Map
int findPairs(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 1)
    {
        return 0;
    }
    unordered_map<int, int> mp;

    for (int x : nums)
    {
        mp[x]++;
    }

    int count = 0;
    for (auto x : mp)
    {
        if (k == 0)
        {
            if (x.second > 1)
            {
                count++;
            }
        }
        else
        {
            if (mp.find(x.first + k) != mp.end())
            {
                count++;
            }
        }
    }
    return count;
}
// By BinarySearch
int findPairs(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 1)
    {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int count = 0;
    int i = 0;
    while (i < n)
    {
        int val = nums[i];
        int low = i + 1;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] - val == k)
            {
                count++;
                break;
            }
            else if (nums[mid] - val < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (i != n - 1 && nums[i] == nums[i + 1])
        {
            while (i < n && val == nums[i])
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    return count;
}

// By Two Pointers
int findPairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int ans = 0, i = 0, j = 1;
    for (i, j; i < nums.size() and j < nums.size();)
    {
        if (i == j or nums[j] - nums[i] < k)
            j++;
        else
        {
            if (nums[j] - nums[i] == k)
            {
                ans++;
                j++;
                for (; j < nums.size(); j++)
                    if (nums[j] != nums[j - 1])
                        break;
                if (j == nums.size())
                    return ans;
                j--;
            }
            i++;
            while (i < j and nums[i] == nums[i - 1])
                i++;
        }
    }
    return ans;
}
int main()
{
    return 0;
}