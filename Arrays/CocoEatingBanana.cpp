#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

bool isValid(vector<int> &piles, int h, long mid)
{
    long sum = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        sum += (long)ceil((long)piles[i] * 1.0 / mid);
    }
    return (sum <= h);
}

int minEatingSpeed(vector<int> &piles, int h)
{
    long low = 1;
    long high = *max_element(piles.begin(), piles.end());
    int ans = INT_MAX;
    while (low <= high)
    {
        long mid = low + ((high - low) >> 1);
        if (isValid(piles, h, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    return 0;
}