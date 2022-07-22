#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int max = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            if (count > max)
            {
                max = count;
            }
            count = 0;
        }
        else
        {
            count++;
        }
    }
    if (count > max)
    {
        max = count;
    }
    return max;
}

int main()
{
    return 0;
}