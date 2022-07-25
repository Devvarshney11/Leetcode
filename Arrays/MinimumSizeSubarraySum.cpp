#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;

// BruteForce
int minSubArrayLen(int target, vector<int> nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    int count = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum >= target)
            {
                count = min(i - j + 1, count);
                break;
            }
        }
    }
    return (count != INT_MAX) ? count : 0;
}

// By Two Pointer apparoach
int minSubArrayLen(int target, vector<int> nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    int count = INT_MAX;
    int left = 0;
    int right = 0;
    int sum = 0;
    while (right < n)
    {
        sum += nums[right];
        if (sum >= target)
        {
            count = min(count, right - left + 1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return (count != INT_MAX) ? count : 0;
}
int main()
{
    return 0;
}