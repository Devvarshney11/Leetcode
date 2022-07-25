#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n == 2)
    {
        return {1, 2};
    }

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int val = nums[left] + nums[right];
        if (val == target)
        {
            break;
        }
        else if (val > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return {left + 1, right + 1};
}

int main()
{
    return 0;
}