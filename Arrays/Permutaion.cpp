#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
void permutation(vector<vector<int>> &ans, int index, vector<int> &nums)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        permutation(ans, index + 1, nums);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    permutation(ans, 0, nums);
    return ans;
}
int main()
{
    return 0;
}