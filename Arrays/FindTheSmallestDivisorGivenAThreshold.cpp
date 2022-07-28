#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isValid(vector<int> &nums, int thres, int mid)
{
    int sum = 0;
    for (int x : nums)
    {
        if (x < mid)
        {
            sum++;
        }
        else
        {
            int temp = x;
            while (temp > 0)
            {
                sum++;
                temp -= mid;
            }
        }
        if (sum > thres)
            return false;
    }
    return true;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    int ans = 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (isValid(nums, threshold, mid))
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