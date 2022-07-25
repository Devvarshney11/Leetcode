#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// Brute force
//  vector<int> targetIndices(vector<int> &nums, int target)
//  {
//      vector<int> ans;
//      int n = nums.size();
//      if (n == 1)
//      {
//          if (nums[0] == target)
//          {
//              ans.push_back(0);
//          }
//          return ans;
//      }
//      sort(nums.begin(), nums.end());
//      int i = 0;
//      while (i < n)
//      {
//          while (i < n && nums[i] == target)
//          {
//              ans.push_back(i);
//              i++;
//          }
//          i++;
//      }
//      return ans;
//  }

// By Binary Search
int firstIndex(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    int ans = -1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (nums[mid] == target)
        {
            ans = mid;
            high = mid - 1;
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
    return ans;
}
int lastIndex(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    int ans = -1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (nums[mid] == target)
        {
            ans = mid;
            low = mid + 1;
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
    return ans;
}
vector<int> targetIndices(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<int> ans;
    if (nums.size() == 1)
    {
        if (nums[0] == target)
        {
            ans.push_back(0);
        }
        return ans;
    }
    int first = firstIndex(nums, target);
    int last = lastIndex(nums, target);

    if (first == -1 && last == -1)
    {
        return ans;
    }
    else if (first == last)
    {
        ans.push_back(first);
    }
    else
    {
        for (int i = first; i <= last; i++)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    return 0;
}