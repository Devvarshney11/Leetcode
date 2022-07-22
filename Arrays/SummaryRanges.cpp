#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<string> summaryRanges(vector<int> &nums)
{
    int count = 0;
    string temp = "";
    vector<string> ans;
    int i = 0;
    while (i < nums.size())
    {
        if (temp == "")
        {
            temp += to_string(nums[i]);
        }
        if (i < nums.size() - 1 && (long)abs((long)nums[i] - (long)nums[i + 1]) == 1)
        {
            count++;
            i++;
        }
        else
        {
            if (count != 0)
            {
                temp += "->";
                temp += to_string(nums[i]);
            }
            ans.push_back(temp);
            temp = "";
            count = 0;
            i++;
        }
    }
    return ans;
}
int main()
{
    return 0;
}