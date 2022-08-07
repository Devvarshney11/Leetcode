#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] == key)
            return mid;
        else if (nums[mid] > key)
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
int arithmeticTriplets(vector<int> &nums, int diff)
{
    int i = 0;
    int j = 1;
    int n = nums.size();
    int count = 0;
    while (j < n - 1)
    {
        int val = nums[j] - nums[i];
        if (val == diff)
        {
            int index = binarySearch(nums, j, n - 1, nums[j] + diff);
            if (index != -1)
                count++;
            i++;
            j++;
        }
        else if (val < diff)
        {
            j++;
        }
        else if (val > diff)
        {
            i++;
        }
    }
    return count;
}

int main()
{
    return 0;
}