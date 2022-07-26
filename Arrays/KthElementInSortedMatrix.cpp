#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int row = matrix.size();
    int col = matrix[0].size();

    int low = matrix[0][0];
    int high = matrix[row - 1][col - 1];

    while (low < high)
    {
        int mid = low + ((high - low) >> 1);
        int temp = col - 1;
        int count = 0;

        // Counting number of smallest element than mid
        for (int i = 0; i < row; i++)
        {
            while (temp >= 0 && matrix[i][temp] > mid)
            {
                temp--;
            }
            count += temp + 1;
        }
        if (count >= k)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    return 0;
}