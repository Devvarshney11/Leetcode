#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> finalPrices(vector<int> &prices)
{
    int n = prices.size();
    vector<int> ans(n);

    stack<int> st;
    st.push(0);

    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != 0 && prices[i] < st.top())
        {
            st.pop();
        }
        if (st.top() == 0)
        {
            ans[i] = prices[i];
        }
        else
            ans[i] = prices[i] - st.top();
        st.push(prices[i]);
    }

    return ans;
}
int main()
{
    return 0;
}