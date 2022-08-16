#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

void reverse(queue<int> &q,int k)
{
    stack<int> st;
    int n = q.size();
    for(int i = 0;i<k;i++)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    k = n-k;
    while(k--)
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
return 0;
}