#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
void moveZeroes(vector<int> &nums)
{
    int ptr1 = 0;
    int ptr2 = 0;
    while (ptr2 < nums.size())
    {
        if (nums[ptr2] == 0)
        {
            ptr2++;
        }
        else
        {
            swap(nums[ptr2], nums[ptr1]);
            ptr2++;
            ptr1++;
        }
    }
}
int main()
{
    return 0;
}