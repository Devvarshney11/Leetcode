#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int num;
int guess(int val)
{
    if (val > num)
    {
        return -1;
    }
    else if (val < num)
    {
        return 1;
    }
    return 0;
}
int guessNumber(int n)
{
    int left = 1;
    int right = n;
    int ans = 0;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (guess(mid) == 0)
        {
            ans = mid;
            break;
        }
        else if (guess(mid) < 0)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}
int main()
{
    return 0;
}