#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isRedundant(string s)
{
    stack<char> st;
    for (auto ch : s)
    {
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            if (!st.empty() && st.top() == ')')
            {
                return true;
            }
            else
            {
                while (!st.empty() && st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    return 0;
}