#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int calPoints(vector<string> &ops)
{
    stack<int> st;
    for (auto s : ops)
    {
        if (!st.empty() && s == "C")
        {
            st.pop();
        }
        else if (!st.empty() && s == "D")
        {
            st.push(2 * st.top());
        }
        else if (!st.empty() && s == "+")
        {
            int val = st.top();
            st.pop();
            int n = st.top() + val;
            st.push(val);
            st.push(n);
        }
        else
        {
            st.push(stoi(s));
        }
    }
    int sum = 0;
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    return sum;
}

int main()
{
    return 0;
}