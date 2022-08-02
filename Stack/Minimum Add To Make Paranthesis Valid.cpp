#include <iostream>
#include <stack>
#include <string>

using namespace std;

int minAddToMakeValid(string s)
{
    stack<char> st;

    for (char &ch : s)
    {
        if (ch == '(')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    return st.size();
}

int main()
{
    return 0;
}