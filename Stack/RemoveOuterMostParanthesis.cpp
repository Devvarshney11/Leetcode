#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Without Stack
string removeOuterParentheses(string s)
{
    string res;
    int opened = 0;
    for (char c : s)
    {
        if (c == '(' && opened++ > 0)
            res += c;
        if (c == ')' && opened-- > 1)
            res += c;
    }
    return res;
}

// With Stack
string removeOuterParentheses(string s)
{
    stack<char> st;
    string ans;
    for (char c : s)
    {
        if (c == ')')
            st.pop();
        if (!st.empty())
            ans += c;
        if (c == '(')
            st.push(c);
    }
    return ans;
}
int main()
{
    return 0;
}