#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int bad;
bool isBadVersion(int version)
{
    if(bad<=version)
    {
        return true;
    }
    return false;
}
int firstBadVersion(int n)
{
    int left = 1;
    int right = n;
    int ans = 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid))
        {
            ans = mid;
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