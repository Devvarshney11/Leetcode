#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int missingNumber(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ nums[i];
        ans = ans ^ i;
    }
    ans = ans ^ n;
    return ans;
}
int main()
{
    return 0;
}