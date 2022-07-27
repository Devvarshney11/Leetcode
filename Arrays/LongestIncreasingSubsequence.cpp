/*
** Given an integer array nums, return the length of the longest strictly increasing subsequence.

** A subsequence is a sequence that can be derived from an array by deleting some or 
** no elements without changing the order of the remaining elements.
** For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> nums)
{
    int n = nums.size();

    if(n == 1)
    {
        return 1;
    }
    vector<int> temp;
    temp.push_back(nums[0]);

    for(int i = 1;i<n;i++)
    {
        if(nums[i]>temp.back())
        {
            temp.push_back(nums[i]);
        }
        else
        {
            int idx = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[idx] = nums[i];
        }
    }
    return temp.size();
}
int main()
{
    return 0;
}