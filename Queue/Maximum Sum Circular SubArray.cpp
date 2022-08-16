#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int maxSubarraySumCircular(vector<int> &nums)
{
    int totalSum = 0;

    int mincurrSum = 0, maxcurrSum = 0;
    int remove = INT_MAX;
    int maxSum = INT_MIN;

    for (auto i : nums)
    {
        mincurrSum += i;
        remove = (mincurrSum < remove) ? mincurrSum : remove;
        mincurrSum = (mincurrSum >= 0) ? 0 : mincurrSum;
        //----------------------------------------------//
        maxcurrSum += i;
        maxSum = (maxcurrSum > maxSum) ? maxcurrSum : maxSum;
        maxcurrSum = (maxcurrSum < 0) ? 0 : maxcurrSum;

        totalSum += i;
    }

    if (remove >= 0)
        maxSum = max(totalSum, maxSum);
    else if (remove != totalSum)
        maxSum = max(totalSum - remove, maxSum);
    return maxSum;
}

int main()
{
    return 0;
}