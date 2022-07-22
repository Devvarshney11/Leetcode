#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    map<int, int> m;
    stack<int> st;
    st.push(-1);
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (st.top() != -1 && nums2[i] >= st.top())
        {
            st.pop();
        }
        m.insert({nums2[i], st.top()});
        st.push(nums2[i]);
    }
    vector<int> ans;
    for (int n : nums1)
    {
        ans.push_back(m[n]);
    }
    return ans;
}
int main()
{
    return 0;
}