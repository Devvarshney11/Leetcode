#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int minValue = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        minValue = min(minValue, prices[i]);
        maxProfit = max((prices[i] - minValue), maxProfit);
    }
    return maxProfit;
}

int main()
{
    return 0;
}