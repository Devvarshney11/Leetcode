#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int res = nums[0] + nums[1] + nums[nums.size() - 1];
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            int sum = nums[i] + nums[low] + nums[high];
            if (target > sum)
            {
                low++;
            }
            else
            {
                high--;
            }
            if (abs(sum - target) < abs(res - target))
            {
                res = sum;
            }
        }
    }
    return res;
}

int main()
{
    return 0;
}