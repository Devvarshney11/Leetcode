#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// By Binary Search
// int missingNumber(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     int left = 0;
//     int right = nums.size();
//     while (left < right)
//     {
//         int mid = left + (right - left) / 2;
//         if (nums[mid] > mid)
//             right = mid;
//         else
//             left = mid + 1;
//     }
//     return left;
// }

int missingNumber(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ nums[i];
        ans = ans ^ i;
    }
    ans = ans ^ n;
    return ans;
}
int main()
{
    return 0;
}