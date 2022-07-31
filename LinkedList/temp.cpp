#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string decodeString(string s)
{
    stack<string> st;

    string ans = "";
    string temp;
    string temp1;
    string temp2;
 
    int val;
    int i = s.length() - 1;
    while (i >= 0)
    {
        if (s[i] == ']')
        {
            st.push("]");
            i--;
            while (i >= 0 && !st.empty())
            {
                temp = "";
                temp2 = "";
                if (!st.empty() && st.top() != "]")
                {
                    temp = st.top();
                    st.pop();
                }
                while (i >= 0 && s[i] != '[')
                {
                    if (s[i] == ']')
                    {
                        st.push("]");
                        temp2 = temp;
                        temp = "";
                        i--;
                    }
                    temp = s[i] + temp;
                    i--;
                }
                i--;
                st.pop();
                val = s[i] - '0';
                i--;
                temp1 = "";
                while (val--)
                {
                    temp1 += temp;
                }
                if (!st.empty() && st.top() == "]")
                    st.push(temp1 + temp2);
                else
                {
                    ans = temp1 + ans;
                }
            }
        }
        else
        {
            temp = "";
            while (i >= 0 && s[i] != ']')
            {
                temp = s[i] + temp;
                i--;
            }
            ans = temp + ans;
        }
    }
    return ans;
}
int main()
{
    return 0;
}