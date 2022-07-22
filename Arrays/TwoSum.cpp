#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    set<int> m;
    vector<int> ans;
    int temp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.count(target - nums[i]))
        {
            ans.push_back(i);
            temp = nums[i];
            break;
        }
        m.insert(nums[i]);
    }
    temp = target - temp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (temp == nums[i])
        {
            ans.push_back(i);
            break;
        }
    }
    return ans;
}
int main()
{
    return 0;
}