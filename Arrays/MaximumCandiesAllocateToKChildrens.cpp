#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isValid(vector<int> &candies, long long k, long long mid)
{
    long long split = 0;
    for (int i = 0; i < candies.size(); ++i)
    {
        split += candies[i] / mid;
    }
    if (split >= k)
        return true;
    else
        return false;
}
int maximumCandies(vector<int> &candies, long long k)
{
    long long low = 1;
    long long high = 0;
    for (int c : candies)
    {
        high += c;
    }
    if (k > high)
    {
        return 0;
    }
    high = high / k;
    int ans = 0;
    while (low <= high)
    {
        long long mid = low + ((high - low) >> 1);

        if (isValid(candies, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    return 0;
}