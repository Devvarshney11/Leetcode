#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int low = 0;
    int high = row * col - 1;

    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        int val = matrix[mid / col][mid % col];   // Address of val in memory is i*col+j;

        if (val == target)
        {
            return true;
        }
        else if (val > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

int main()
{
    return 0;
}