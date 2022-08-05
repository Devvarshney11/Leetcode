#include <iostream>
#include <string>
#include <stack>

using namespace std;

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

int main()
{
    return 0;
}