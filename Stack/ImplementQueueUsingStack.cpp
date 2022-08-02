#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MyQueue
{
public:
    stack<int> st;
    void insertAtBottom(int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }
        int ele = st.top();
        st.pop();
        insertAtBottom(x);
        st.push(ele);
    }
    MyQueue()
    {
    }

    void push(int x)
    {
        insertAtBottom(x);
    }

    int pop()
    {
        if (st.empty())
            return -1;
        int ele = st.top();
        st.pop();
        return ele;
    }

    int peek()
    {
        if (st.empty())
            return -1;
        return st.top();
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