#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int jump(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 0;
    }
    int i = 0;
    int count = 1;
    int reach = nums[0];
    int curr = nums[0];
    while (i < nums.size() - 1)
    {
        reach = max(i + nums[i], reach);
        if (curr == i)
        {
            count++;
            curr = reach;
        }
        i++;
    }
    return count;
}

int main()
{
    return 0;
}