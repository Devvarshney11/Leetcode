#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> st;

    for (auto &str : tokens)
    {
        if (str == "+" || str == "-" || str == "*" || str == "/")
        {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            if (str == "+")
                st.push(num1 + num2);
            else if (str == "-")
                st.push(num2 - num1);
            else if (str == "*")
                st.push(num2 * num1);
            else if (str == "/")
                st.push(num2 / num1);
        }
        else
            st.push(stoi(str));
    }

    return st.top();
}

int main()
{
    return 0;
}