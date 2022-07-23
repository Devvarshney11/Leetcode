#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    int count = 1;
    int left = 0;
    int right = n - 1;
    int top = 0;
    int down = n - 1;
    vector<vector<int>> ans(n, vector<int>(n));
    while (left <= right && top <= down)
    {
        for (int i = left; i <= right; i++)
        {
            ans[top][i] = count;
            count++;
        }
        top++;

        if (left <= right && top <= down)
            for (int i = top; i <= down; i++)
            {
                ans[i][right] = count;
                count++;
            }
        right--;

        if (left <= right && top <= down)
            for (int i = right; i >= left; i--)
            {
                ans[down][i] = count;
                count++;
            }
        down--;

        if (left <= right && top <= down)
            for (int i = down; i >= top; i--)
            {
                ans[i][left] = count;
                count++;
            }
        left++;
    }
    return ans;
}
int main()
{
    return 0;
}