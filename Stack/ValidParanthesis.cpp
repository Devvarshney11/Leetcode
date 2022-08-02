#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> st;

    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if ((!st.empty() && s[i] == ']' && st.top() == '[') || (!st.empty() && s[i] == '}' && st.top() == '{') || (!st.empty() && s[i] == ')' && st.top() == '('))
        {
            st.pop();
        }
        else
        {
            return false;
        }
        i++;
    }
    return (st.empty());
}

int main()
{
    return 0;
}