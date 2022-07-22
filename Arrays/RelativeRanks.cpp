#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> findRelativeRanks(vector<int> &score)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < score.size(); i++)
    {
        pq.push({score[i], i});
    }
    int i = 0;
    vector<string> ans(score.size());
    while (!pq.empty())
    {
        ans[pq.top().second] = i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal"
                                                   : i == 2   ? "Bronze Medal"
                                                              : to_string(i + 1);
        i++;
        pq.pop();
    }
    return ans;
}
int main()
{
    return 0;
}