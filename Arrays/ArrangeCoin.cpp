#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// By Brute Force
//  int arrangeCoins(int n)
//  {
//      int count = 0;
//      int i = 1;
//      while (true)
//      {
//          if (i <= n)
//          {
//              count++;
//              n = n - i;
//              i++;
//          }
//          if (i > n)
//          {
//              break;
//          }
//      }
//      return count;
//  }

// By Binary Search
int arrangeCoins(int n)
{
    long left = 1;
    long right = n;
    while (left <= right)
    {
        long mid = left + ((right - left) >> 1);
        long curr = (mid * (mid + 1)) >> 1;
        if (curr == n)
        {
            return (int)mid;
        }
        if (curr > n)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return (int)right;
}

int main()
{
    return 0;
}