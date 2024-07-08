#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculate(string s) {
        int n = s.length();
        stack<int> st;
        int currChar = '+';
        for(int i = 0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                int curr = 0;
                while(i<n && isdigit(s[i]))
                {
                    curr = curr*10+(s[i]-'0');
                    i++;
                }  
                i--;
                
                if(currChar == '+')
                {
                    st.push(curr);
                }
                else if(currChar == '-')
                {
                    st.push(-curr);
                }
                else if(currChar == '*')
                {
                    int a = st.top();
                    st.pop();
                    st.push(a*curr);
                }
                else if(currChar == '/')
                {
                    int a = st.top();
                    st.pop();
                    st.push(a/curr);
                }
            }
            else if(s[i] != ' ')
            {
                currChar = s[i];
            }
        }
        int sum = 0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
int main()
{
    return 0;
}
