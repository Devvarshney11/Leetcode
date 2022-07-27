#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
bool judgeSquareSum(int c)
{
    long long low = 0;
    long long high = sqrt(c);
    while (low <= high)
    {
        long long val = low * low + high * high;
        if (val == c)
            return true;
        else if (val < c)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return false;
}
int main()
{
    return 0;
}