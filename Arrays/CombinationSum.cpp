#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
// This question is done by include and exclude principle
void findCombination(vector<int> &can, int index, int target, vector<int> &output, vector<vector<int>> &ans)
{
    if (index == can.size())
    {
        if (target == 0)
        {
            ans.push_back(output);
        }
        return;
    }

    // Include
    if (can[index] <= target)
    {
        output.push_back(can[index]);
        findCombination(can, index, target - can[index], output, ans);
        // We do backtrack because of the exclusion
        output.pop_back();
    }
    // Exclude
    findCombination(can, index + 1, target, output, ans);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> output;
    findCombination(candidates, 0, target, output, ans);
    return ans;
}
int main()
{
    return 0;
}