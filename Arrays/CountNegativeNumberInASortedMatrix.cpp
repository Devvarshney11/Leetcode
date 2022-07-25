#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int countNegatives(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    int low = 0;
    int high = c - 1;
    int count = 0;
    while (low < r && high >= 0)
    {
        if (grid[low][high] < 0)
        {
            count++;
            if (high == 0 && low < r - 1 && grid[low + 1][c - 1] < 0)
            /*This condition is for this case
            -1,-2,-3,-4,-5
             4, 3, 2, 1,-1
             If in first row our loop got terminate then we got wrong output
             so we update high and point to last of next row
            */
            {
                high = c - 1;
                low++;
            }
            else
                high--;
        }
        else
        {
            low++;
            high = c - 1; // After completion of one row update to point the last of next row
        }
    }
    return count;
}
int main()
{
    return 0;
}