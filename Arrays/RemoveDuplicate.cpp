#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int remove(vector<int> &nums)
{
    int left = 0;
    int right = 0;
    int n = nums.size();
    while(right<n)
    {
        if(nums[left] != nums[right])
        {
            left++;
        }
        nums[left] = nums[right];
        right++; 
    }
    return left+1;
}
int main()
{ 
  vector<int> nums{0,0,1,1,1,2,2,3,3,4};
  int n = remove(nums);
  for(int i = 0;i<n;i++)
  {
     cout<<nums[i]<<" ";
  }
  return 0;
}