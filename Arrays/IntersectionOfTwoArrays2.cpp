#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

// By map
// vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
// {
//     vector<int> ans;
//     map<int, int> m;
//     for (auto x : nums1)
//     {
//         m[x]++;
//     }
//     for (auto x : nums2)
//     {
//         if (m[x] > 0)
//         {
//             ans.push_back(x);
//             m[x]--;
//         }
//     }
//     return ans;
//}

// By Binary Search
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0;
    int j = 0;
    int n = nums1.size();
    int m = nums2.size();

    vector<int> ans;
    while (i < n && j < m)
    {
        int one = nums1[i];
        int two = nums2[j];

        if (one == two)
        {
            ans.push_back(one);
            i++;
            j++;
        }
        else if (one < two)
        {
            while (i < n && one == nums1[i])
                i++;
        }
        else
        {
            while (j < m && two == nums2[j])
                j++;
        }
    }
    return ans;
}
int main()
{
    return 0;
}