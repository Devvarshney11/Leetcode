#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (M[a][b] == 1)
        {
            st.push(b);
        }
        else if (M[b][a] == 1)
        {
            st.push(a);
        }
    }
    int celeb = st.top();
    st.pop();
    bool rowCheck = false;
    bool colCheck = false;
    // row check
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[celeb][i] == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount == n)
    {
        rowCheck = true;
    }

    // colCheck
    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][celeb] == 1)
        {
            oneCount++;
        }
    }
    if (oneCount == n - 1)
    {
        colCheck = true;
    }

    if (rowCheck == true && colCheck == true)
        return celeb;
    return -1;
}

int main()
{
    return 0;
}