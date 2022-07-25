#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

// By Binary Search
// vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
// {
//     sort(nums1.begin(), nums1.end());
//     sort(nums2.begin(), nums2.end());

//     int i = 0;
//     int j = 0;
//     int n = nums1.size();
//     int m = nums2.size();

//     vector<int> ans;
//     while (i < n && j < m)
//     {
//         int one = nums1[i];
//         int two = nums2[j];

//         if (one == two)
//         {
//             ans.push_back(one);
//             while (i < n && one == nums1[i])
//                 i++;
//             while (j < m && two == nums2[j])
//                 j++;
//             continue;
//         }
//         if (one < two)
//         {
//             while (i < n && one == nums1[i])
//                 i++;
//         }
//         else
//         {
//             while (j < m && two == nums2[j])
//                 j++;
//         }
//     }
//     return ans;
// }

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