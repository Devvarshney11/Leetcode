#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
int triangleCount(vector<int> nums)
{
    sort(nums.begin(),nums.end());
    
    int count = 0;
    for(int i = nums.size()-1;i>=0;i--)
    {
        int low = 0;
        int high = i-1;
 
        while(low<high)
        {
            if(nums[low]+nums[high]>nums[i])
            {
                count += high-low;
                high--;
            }
            else
            {
                low++;
            }
        }
    }
    return count;
}
int main()
{
return 0;
}