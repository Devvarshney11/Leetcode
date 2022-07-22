#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{

    // edge case
    if (nums.size() == 1)
    {
        return false;
    }
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m[nums[i]])
        {
            if (abs(m[nums[i]] - (i + 1)) <= k)
            {
                return true;
            }
        }
        m[nums[i]] = i + 1;
    }
    return false;
}
int main()
{
    return 0;
}