#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int layer = n / 2;
    for (int l = 0; l < layer; l++)
    {
        int s = l;
        int e = n - l - 1;
        for (int i = s; i < e; i++)
        {
            int temp = matrix[s][i];

            matrix[s][i] = matrix[n - i - 1][s];
            matrix[n - i - 1][s] = matrix[e][n - i - 1];
            matrix[e][n - i - 1] = matrix[i][e];
            matrix[i][e] = temp;
        }
    }
}

int main()
{
    return 0;
}