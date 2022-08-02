#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Without Stack

int maxDepth(string s)
{
    int maxCount = 0;
    int count = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
            maxCount = max(maxCount, ++count);
        }
        else if (ch == ')')
        {
            count--;
        }
    }
    return maxCount;
}

// WithStack
int maxDepth(string s)
{
    stack<char> st;
    int maxCount = 0;
    int count = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
          st.push(ch);
          count++;
        }
        else if (ch == ')')
        {
           maxCount = max(maxCount,count);
           st.pop();
           count = st.size();
        }
    }
    return maxCount;
}

int main()
{
    return 0;
}