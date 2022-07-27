#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int distance(vector<int> &nums, int key)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (nums[mid] == key)
        {
            return 0;
        }
        else if (nums[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (low == nums.size())
        return key - nums[high];
    else if (high == -1)
        return nums[low] - key;

    return min(nums[low] - key, key - nums[high]);
}
int findRadius(vector<int> &houses, vector<int> &heaters)
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    sort(heaters.begin(), heaters.end());

    int ans = INT_MIN;
    for (int h : houses)
    {
        int dis = distance(heaters, h);
        ans = max(dis, ans);
    }
    return ans;
}

int main()
{
    return 0;
}