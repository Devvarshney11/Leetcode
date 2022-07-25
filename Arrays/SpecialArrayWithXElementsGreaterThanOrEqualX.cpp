/*
You are given an array nums of non-negative integers.
nums is considered special if there exists a number x
such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1.
It can be proven that if nums is special, the value for x is unique.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// BruteForce
// int specialArray(vector<int> nums)
// {
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     if (nums[0] >= n)
//     {
//         return n;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int count = n-i;

//         if(nums[i]>=count && nums[i-1]<count)
//         {
//             return count;
//         }
//     }
//     return -1;
// }


// By BinarySearch
int specialArray(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (nums[0] >= n)
    {
        return n;
    }

    for (int i = 0; i < n; i++)
    {
        int temp = n;
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] >= i)
            {
                temp = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if ((n - temp) == i)
            return i;
    }
    return -1;
}
int main()
{
    return 0;
}