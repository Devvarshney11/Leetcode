#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack
{
public:
    long min;
    stack<long> st;
    MinStack()
    {
        min = INT_MAX;
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            min = val;
            return;
        }
        if (val < min)
        {
            long data = 2 * (long)val - min;
            st.push(data);
            min = val;
        }
        else
        {
            st.push(val);
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        if (st.top() < min)
        {
            min = 2 * (long)min - st.top();
            st.pop();
        }
        else
        {
            st.pop();
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        if (st.top() <= min)
        {
            return min;
        }
        return st.top();
    }

    int getMin()
    {
        return (long)min;
    }
};

int main()
{
    return 0;
}