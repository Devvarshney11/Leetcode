#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int m = matrix.size(), n = matrix[0].size();

    if (m == 0 || n == 0)
        return res;

    int left = 0, right = n - 1, top = 0, bottom = m - 1;

    while (left <= right && top <= bottom)
    {
        for (int j = left; j <= right; j++)
        {
            res.push_back(matrix[top][j]);
        }
        top++;

        if (left <= right && top <= bottom)
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
        right--;

        if (left <= right && top <= bottom)
            for (int j = right; j >= left; j--)
            {
                res.push_back(matrix[bottom][j]);
            }
        bottom--;

        if (left <= right && top <= bottom)
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
        left++;
    }

    return res;
}
int main()
{
    return 0;
}