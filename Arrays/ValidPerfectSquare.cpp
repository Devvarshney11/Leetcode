#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isPerfectSquare(int num)
{
    int low = 0;
    int high = 46340;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long sqrt = mid * mid;
        if (sqrt == num)
        {
            return true;
        }
        if (sqrt > num)
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