/*
**You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

** The right interval for an interval i is an interval j such that startj >= endi and startj is minimized.
** Note that i may equal j.

** Return an array of right interval indices for each interval i.
** If no right interval exists for interval i, then put -1 at index i.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> findRightInterval(vector<vector<int>> &intervals)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n = intervals.size();
    if (n == 1)
    {
        return {-1};
    }
    vector<pair<pair<int, int>, int>> temp;

    for (int i = 0; i < n; i++)
    {
        temp.push_back({{intervals[i][0], intervals[i][1]}, i});
    }

    sort(temp.begin(), temp.end());
    vector<int> right(n, -1);

    for (int i = 0; i < n; i++)
    {
        int low = 0;
        int high = n;

        int end = intervals[i][1];

        while (low < high)
        {
            int mid = low + ((high - low) >> 1);
            if (temp[mid].first.first >= end)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (high != n)
        {
            right[i] = temp[high].second;
        }
    }
    return right;
}
int main()
{
    return 0;
}