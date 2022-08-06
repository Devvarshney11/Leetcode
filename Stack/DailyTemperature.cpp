#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temp)
{
    stack<int> st;
    int n = temp.size();
    vector<int> warm(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && temp[st.top()] <= temp[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            warm[i] = 0;
        }
        else
        {
            warm[i] = st.top() - i;
        }
        st.push(i);
    }
    return warm;
}

int main()
{
    return 0;
}