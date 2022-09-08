#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int minimumRecolors(string blocks, int k)
{
    int recolor = INT_MAX;
    int n = blocks.length();

    for (int i = 0; i + k - 1 < n; i++)
    {
        int white = 0;
        for (int j = 0; j < k; j++)
        {
            if (blocks[j + i] == 'W')
            {
                white++;
            }
        }
        if (white < recolor)
        {
            recolor = white;
        }
    }
    return recolor;
}
int main()
{
    return 0;
}