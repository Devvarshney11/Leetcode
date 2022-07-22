#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int maxArea(vector<int> &height)
{
    int max = INT_MIN;
    int low = 0;
    int high = height.size() - 1;
    while (low <= high)
    {
        int min;
        if (height[low] < height[high])
        {
            min = height[low];
        }
        else
        {
            min = height[high];
        }
        int area = (high - low) * min;
        if (area > max)
        {
            max = area;
        }
        if (min == height[low])
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return max;
}
int main()
{
    return 0;
}