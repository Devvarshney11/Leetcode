#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n == 1)
    {
        return (nums[0] == target) ? 0 : -1;
    }
    int ans = -1;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] == target)
        {
            return mid;
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
    return -1;
}

int main()
{
    return 0;
}