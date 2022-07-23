#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
        }
        else if (intervals[i][0] > newInterval[1])
        {
            ans.push_back(newInterval);
            newInterval = intervals[i];
        }
        else if (intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
        }
    }
    ans.push_back(newInterval);
    return ans;
}
int main()
{
    return 0;
}