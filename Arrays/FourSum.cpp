#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    // Edge case
    int n = nums.size();
    if (n < 4)
    {
        return ans;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        long val1 = target - nums[i];
        for (int j = i + 1; j < n; j++)
        {
            long val2 = val1 - nums[j];
            int start = j + 1;
            int end = n - 1;
            while (start < end)
            {
                long sum = nums[start] + nums[end];
                if (sum > val2)
                {
                    end--;
                }
                else if (sum < val2)
                {
                    start++;
                }
                else if (sum == val2)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);

                    ans.push_back(temp);

                    while (start < end && nums[start] == temp[2])
                    {
                        start++;
                    }
                    while (start < end && nums[end] == temp[3])
                    {
                        end--;
                    }
                }
            }
            while (j + 1 < n && nums[j + 1] == nums[j])
            {
                j++;
            }
        }
        while (i + 1 < n && nums[i + 1] == nums[i])
        {
            i++;
        }
    }
    return ans;
}
int main()
{
    return 0;
}