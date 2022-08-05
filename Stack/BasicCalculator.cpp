#include <iostream>
#include <stack>
#include <string>

using namespace std;

// By Stack
int calculate(string s)
{
    stack<pair<int, int>> st;

    int i = 0;
    int n = s.length();
    int sum = 0;
    int sign = +1;
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            int digit = 0;
            while (i < n && isdigit(s[i]))
            {
                digit = digit * 10 + (s[i] - '0');
                i++;
            }
            i--;
            sum += digit * sign;
            sign = +1;
        }
        else if (s[i] == '(')
        {
            st.push({sum, sign});
            sum = 0;
            sign = +1;
        }
        else if (s[i] == ')')
        {
            sum = st.top().first + st.top().second * sum;
            st.pop();
        }
        else if (s[i] == '-')
        {
            sign = -1 * sign;
        }
    }
    return sum;
}

// By recursion
int solve(string s, int &index)
{
    char currChar = '+';
    int sum = 0;
    while (index < s.length())
    {
        if (s[index] == ')')
        {
            index++;
            return sum;
        }
        else if (s[index] == '(')
        {
            index++;
            int curr = solve(s, index);
            if (currChar == '+')
            {
                sum += curr;
            }
            else if (currChar == '-')
            {
                sum -= curr;
            }
        }
        else if (isdigit(s[index]))
        {
            int curr = 0;
            while (index < s.length() && isdigit(s[index]))
            {
                curr = curr * 10 + (s[index] - '0');
                index++;
            }
            if (currChar == '+')
            {
                sum += curr;
            }
            else if (currChar == '-')
            {
                sum -= curr;
            }
        }
        else if (s[index] == ' ')
        {
            index++;
        }
        else
        {
            currChar = s[index];
            index++;
        }
    }
    return sum;
}
int calculate(string s)
{
    int index = 0;
    return solve(s, index);
}

int main()
{
    return 0;
}