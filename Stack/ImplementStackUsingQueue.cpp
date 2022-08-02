#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> st;
    MyStack()
    {
    }

    void push(int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }
        st.push(x);
        int s = st.size();
        while (s > 1)
        {
            st.push(st.front());
            st.pop();
            s--;
        }
    }

    int pop()
    {
        if (st.empty())
            return -1;
        int ele = st.front();
        st.pop();
        return ele;
    }

    int top()
    {
        if (st.empty())
            return -1;
        return st.front();
    }

    bool empty()
    {
        return st.empty();
    }
};

int main()
{
    return 0;
}