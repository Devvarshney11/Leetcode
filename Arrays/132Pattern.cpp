#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

bool find132pattern(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
    {
        return false;
    }
    if (n == 3)
    {
        return (nums[2] > nums[0] && nums[2] < nums[1]);
    }
    int third = INT_MIN;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] < third)
            return true;
        while (!st.empty() && nums[i] > st.top())
        {
            third = st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return false;
}
int main()
{
    return 0;
}