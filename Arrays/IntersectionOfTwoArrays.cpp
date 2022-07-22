#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    set<int> s(nums1.begin(), nums1.end());
    vector<int> ans;
    for (int i : nums2)
    {
        if (s.count(i))
        {
            ans.push_back(i);
            s.erase(i);
        }
    }
    return ans;
}
int main()
{
    return 0;
}