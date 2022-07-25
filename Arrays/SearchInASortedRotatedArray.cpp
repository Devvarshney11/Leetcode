#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

//By Pivot Method
int pivotIndex(vector<int> nums)
{
    int n = nums.size();
    if(nums[0]<nums[n-1])
    {
        return 0;
    }
    int low = 0;
    int high = n-1;

    while(low<high)
    {
        int mid = low + ((high-low)>>1);

        if(nums[mid]>=nums[0])
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}
int search(vector<int> nums,int target)
{
    int p = pivotIndex(nums);
    int high , low;
    if(target>=nums[0] && target<=nums[p-1])
    {
        low = 0;
        high = p-1;
    }
    else
    {
        low = p;
        high = nums.size()-1;
    }
    while(low<=high)
    {
        int mid = low + ((high-low)>>1);

        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid]>target)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}

//Another Apparoach
int search(vector<int> nums,int target)
{
    int low = 0;
    int high = nums.size()-1;
    while(low<=high)
    {
        int mid = low + ((high-low)>>1);

        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid]>nums[low])
        {
            if(target>=nums[low] && target<nums[mid])
            {
                high = mid-1;
            }
            else
            {
                low  = mid+1;
            }
        }
        else
        {
            if(target>nums[mid] && target<=nums[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    return -1;
}


int main()
{
return 0;
}