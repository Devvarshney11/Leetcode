#include <iostream>
#include <map>
#include <vector>

using namespace std;

long long countBadPairs(vector<int> &nums)
{
    map<long long, long long> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mp[nums[i] - i]++;
    }
    long long ans = (long long)n * (long long)(n - 1) / 2;

    for (auto it : mp)
    {
        ans -= (it.second * (it.second - 1) / 2);
    }
    return ans;
}
int main()
{
    return 0;
}