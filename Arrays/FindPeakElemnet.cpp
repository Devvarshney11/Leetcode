#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return nums[0] > nums[1] ? 0 : 1;
    }
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] < nums[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    return 0;
}