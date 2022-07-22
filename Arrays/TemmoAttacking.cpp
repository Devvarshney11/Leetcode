#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int findPoisonedDuration(vector<int> &timeSeries, int duration)
{
    int n = timeSeries.size();
    if (n == 0)
    {
        return 0;
    }
    int poisonDuration = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (timeSeries[i + 1] - timeSeries[i] < duration)
        {
            poisonDuration += timeSeries[i + 1] - timeSeries[i];
        }
        else
        {
            poisonDuration += duration;
        }
    }
    return poisonDuration + duration;
}

int main()
{
    return 0;
}