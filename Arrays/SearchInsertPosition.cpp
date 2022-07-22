#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    if (target > nums[n - 1])
    {
        return n;
    }
    if (target < nums[0])
    {
        return 0;
    }
    int low = 0;
    int high = n - 1;
    int ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            break;
        }
        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    return 0;
}