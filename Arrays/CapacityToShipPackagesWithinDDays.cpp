#include <iostream>
#include <climits>
#include <vector>

using namespace std;

bool isValid(vector<int> &weights, int days, int mid)
{
    int sum = 0;
    int d = 1;
    for (int w : weights)
    {
        sum += w;
        if (sum > mid)
        {
            d++;
            sum = w;
        }
    }
    return d <= days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int low = INT_MIN;
    int high = 0;

    for (int w : weights)
    {
        high += w;
        if (low < w)
        {
            low = w;
        }
    }
    int ans = high;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (isValid(weights, days, mid))
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