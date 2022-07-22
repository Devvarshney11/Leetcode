#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        int target = 0 - nums[i];
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            int val = nums[low] + nums[high];
            if (val < target)
            {
                low++;
            }
            else if (val > target)
            {
                high--;
            }
            else
            {
                vector<int> triple(3, 0);
                triple[0] = nums[i];
                triple[1] = nums[low];
                triple[2] = nums[high];

                ans.push_back(triple);
                while (low < high && nums[low] == triple[1])
                {
                    low++;
                }
                while (low < high && nums[high] == triple[2])
                {
                    high--;
                }
                while (i + 1 < n && nums[i] == nums[i + 1])
                {
                    i++;
                }
            }
        }
    }
    return ans;
}
int main()
{
    return 0;
}