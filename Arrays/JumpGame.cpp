#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
bool canJump(vector<int> &nums)
{
    int i = 0;
    for (int reach = 0; i < nums.size() && i <= reach; i++)
    {
        reach = max(i + nums[i], reach);
    }
    return i == nums.size();
}
int main()
{
    return 0;
}