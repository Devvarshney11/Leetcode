#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
void findCombination(int idx, int target, vector<vector<int>> &ans, vector<int> &op, vector<int> arr)
{
    if (target == 0)
    {
        ans.push_back(op);
        return;
    }
    for (int i = idx; i < arr.size(); i++)
    {
        if (arr[i] > target)
        {
            break;
        }
        if (i > idx && arr[i] == arr[i - 1])
        {
            continue;
        }
        op.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], ans, op, arr);
        op.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> output;
    sort(candidates.begin(), candidates.end());
    findCombination(0, target, ans, output, candidates);
    return ans;
}
int main()
{
    return 0;
}