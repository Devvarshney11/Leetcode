#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// By Stack
int clumsy(int n)
{
    if (n == 1)
        return 1;
    stack<int> st;
    char chance = '*';
    st.push(n);
    int temp;
    for (int i = n - 1; i > 0; i--)
    {
        switch (chance)
        {
        case '*':
            temp = st.top();
            st.pop();
            st.push(i * temp);
            chance = '/';
            break;
        case '/':
            temp = st.top();
            st.pop();
            st.push(temp / i);
            chance = '+';
            break;
        case '+':
            st.push(i);
            chance = '-';
            break;
        case '-':
            st.push((-1) * i);
            chance = '*';
            break;
        }
    }
    int ans = 0;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

//By math
int clumsy(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 6;
    if(n == 4) return 7;
    if(n%4 == 1) return n+2;
    if(n%4 == 2) return n+2;
    if(n%4 == 3) return n-1;
    return n+1;
    
}
int main()
{
    return 0;
}