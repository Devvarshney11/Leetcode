#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<int> getRow(int rowIndex)
{
    vector<int> ans{1}, curr{1};
    for (int i = 1; i <= rowIndex; i++)
    {
        ans.push_back(1);
        for (int j = 1; j < i; j++)
        {
            ans[j] = curr[j] + curr[j - 1];
        }
        curr = ans;
    }
    return ans;
}
int main()
{
    return 0;
}