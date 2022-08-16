#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        if (q.empty())
        {
            q.push(x);
            return;
        }
        q.push(x);
        int s = q.size();
        while (s > 1)
        {
            q.push(q.front());
            q.pop();
            s--;
        }
    }

    int pop()
    {
        if (q.empty())
            return -1;
        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        if (q.empty())
            return -1;
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};
int main()
{
    return 0;
}