#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<int> prefix;
void NumArray(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (prefix.size() == 0)
        {
            prefix.push_back(nums[i]);
        }
        else
        {
            prefix.push_back(nums[i] + prefix[i - 1]);
        }
    }
}

int sumRange(int left, int right)
{
    if (left == 0)
    {
        return prefix[right];
    }
    return prefix[right] - prefix[left - 1];
}
int main()
{
    return 0;
}