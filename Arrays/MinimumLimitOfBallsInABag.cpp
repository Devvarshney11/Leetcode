#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isValid(vector<int> &nums, int op, int mid)
{
    int count = 0;
    for (int x : nums)
    {
        count += (x - 1) / mid;
        if (count > op)
            return false;
    }
    return true;
}
int minimumSize(vector<int> &nums, int maxOperations)
{
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (isValid(nums, maxOperations, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    return 0;
}