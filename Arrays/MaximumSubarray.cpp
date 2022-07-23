#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int currSum = 0;
    int maxSum = INT_MIN;

    for (auto i : nums)
    {
        currSum += i;
        maxSum = currSum > maxSum ? currSum : maxSum;
        currSum = currSum < 0 ? 0 : currSum;
    }
    return maxSum;
}
int main()
{
    return 0;
}