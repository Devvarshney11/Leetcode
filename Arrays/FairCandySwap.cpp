#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// By Set
// vector<int> fairCandySwap(vector<int> alice, vector<int> bob)
// {
//     int aSum = 0;
//     int bSum = 0;
//     for (auto it : alice)
//     {
//         aSum += it;
//     }
//     for (auto it : bob)
//     {
//         bSum += it;
//     }
//     int delta = (bSum - aSum) / 2;
//     unordered_set<int> s(bob.begin(), bob.end());

//     vector<int> ans;
//     for (auto it : alice)
//     {
//         if (s.find(it + delta) != s.end())
//         {
//             ans.push_back(it);
//             ans.push_back(it + delta);
//         }
//     }
// }

// By Binary Search

int search(vector<int> nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

vector<int> fairCandySwap(vector<int> alice, vector<int> bob)
{
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());

    int aSum = 0;
    for (auto it : alice)
    {
        aSum += it;
    }

    int bSum = 0;
    for (auto it : bob)
    {
        bSum += it;
    }

    vector<int> ans;
    for (auto it : alice)
    {
        int a = aSum - it;
        int b = bSum + it;

        int delta = (b - a) / 2;
        int index = search(bob, delta);
        if (index != -1)
        {
            ans.push_back(it);
            ans.push_back(bob[index]);
            break;
        }
    }
    return ans;
}

int main()
{
    return 0;
}