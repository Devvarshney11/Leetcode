#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int firstPosition(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int lastPosition(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans(2, -1);
    int n = nums.size();
    if (n == 0)
    {
        return ans;
    }
    if (n == 1)
    {
        if (nums[0] == target)
        {
            ans[0] = ans[1] = 0;
        }
        return ans;
    }
    ans[0] = firstPosition(nums, target);
    ans[1] = lastPosition(nums, target);
    return ans;
}
int main()
{
    return 0;
}