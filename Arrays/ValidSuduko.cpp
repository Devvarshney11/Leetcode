#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
bool isValidSudoku(vector<vector<char>> &board)
{
    int checkrow[10][10] = {0};
    int checkcol[10][10] = {0};
    int checkbox[10][10] = {0};

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
                continue;
            int num = board[row][col] - '0';
            int box = (row / 3) * 3 + (col / 3);

            if (checkrow[row][num] || checkcol[num][col] || checkbox[box][num])
            {
                return false;
            }
            checkrow[row][num] = checkcol[num][col] = checkbox[box][num] = 1;
        }
    }
    return true;
}
int main()
{
    return 0;
}