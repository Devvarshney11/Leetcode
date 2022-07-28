#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isValid(vector<int> &nums, int m, int mid)
{
    int sum = 0;
    int count = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum > mid)
        {
            count++;
            sum = nums[i];
        }
    }
    return count <= m;
}
int splitArray(vector<int> &nums, int m)
{
    int low = INT_MIN;
    int high = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        high += nums[i];
        if (nums[i] > low)
            low = nums[i];
    }
    int ans = high;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (isValid(nums, m, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    return 0;
}