#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 1;
    }
    int left = 0;
    for (int right = 1; right < nums.size(); right++)
    {
        if (nums[left] != nums[right])
        {
            left++;
        }
        nums[left] = nums[right];
    }
    return left + 1;
}
int main()
{
    return 0;
}