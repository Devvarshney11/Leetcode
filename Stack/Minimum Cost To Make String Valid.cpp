#include <iostream>
#include <stack>
#include <string>

using namespace std;

int minimumCost(string s)
{
    if(s.length()&1)
    {
        return -1;
    }
    stack<char> st;
    
    for(auto ch : s)
    {
        if(ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if(!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    int a = 0;
    int b = 0;

    while(!st.empty())
    {
        if(st.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    int ans = ((a+1)>>1)  + ((b+1)>>1);
    return ans;
}

int main()
{
    return 0;
}