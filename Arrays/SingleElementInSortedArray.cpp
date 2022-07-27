#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// By XOR

int singleNonDuplicate(vector<int> nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}

// By Binary Search
// By length
int singleNonDuplicate(vector<int> nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }
        else if (nums[mid] == nums[mid - 1])
        {
            int left = mid - low + 1;
            if (left & 1)
            {
                high = mid - 2;
            }
            else
            {
                low = mid + 1;
            }
        }
        else if (nums[mid] == nums[mid + 1])
        {
            int right = high - mid + 1;
            if (right & 1)
            {
                low = mid + 2;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// By index
int singleNonDuplicate(vector<int> nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low < high)
    {
        int mid = (low + high) >> 1;

        if ((mid&1 && nums[mid] == nums[mid - 1]) || (!(mid&1) && nums[mid] == nums[mid + 1]))
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    return nums[low];
}

int main()
{
    return 0;
}