#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> ans;
    for (int n : nums)
    {
        if (nums[abs(n) - 1] > 0)
        {
            nums[abs(n) - 1] *= -1;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans.push_back(i + 1);
        }
    }
    return ans;
}
int main()
{
    return 0;
}