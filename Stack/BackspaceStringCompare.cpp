#include <iostream>
#include <stack>
#include <string>


using namespace std;

bool backspaceCompare(string s, string t)
{
    stack<char> st1;

    for (char ch : s)
    {
        if (!st1.empty() && ch == '#')
        {
            st1.pop();
        }
        else if (ch != '#')
        {
            st1.push(ch);
        }
    }
    string ans1 = "";
    while (!st1.empty())
    {
        ans1 += st1.top();
        st1.pop();
    }
    for (char ch : t)
    {
        if (!st1.empty() && ch == '#')
        {
            st1.pop();
        }
        else if (ch != '#')
        {
            st1.push(ch);
        }
    }
    string ans2 = "";
    while (!st1.empty())
    {
        ans2 += st1.top();
        st1.pop();
    }
    return ans1 == ans2;
}
int main()
{
    return 0;
}