#include <iostream>
#include <stack>
#define MAX 1000
using namespace std;

void nextSmallest(int *arr, int n, int *ans)
{
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
}
void prevSmallest(int *arr, int n, int *ans)
{
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
}
int largestArea(int *arr, int n)
{
    int *next = new int[n];
    int *prev = new int[n];

    nextSmallest(arr, n, next);
    prevSmallest(arr, n, prev);

    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        if (next[i] == -1)
        {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;
        int area = arr[i] * b;

        maxArea = max(area, maxArea);
    }
    delete []next;
    delete []prev;
    return maxArea;
}
int maxArea(int M[MAX][MAX], int n, int m)
{
    // Your code here
    int area = largestArea(M[0], m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }
        area = max(area, largestArea(M[i], m));
    }
    return area;
}
int main()
{
    return 0;
}