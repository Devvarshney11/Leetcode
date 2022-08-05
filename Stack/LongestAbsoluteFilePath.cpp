#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int lengthLongestPath(string input)
{
    input.push_back('\n');
    int level = 0;
    vector<int> levels(300, 0);
    int length = 0;
    int ans = 0;
    bool isfile = false;
    for (auto &ch : input)
    {
        switch (ch)
        {
        case '\n':
            level = 0;
            length = 0;
            isfile = false;
            break;
        case '\t':
            level++;
            length = 0;
            break;
        case '.':
            isfile = true;

        default:
            length++;
            levels[level] = length;
            if (isfile)
            {
                int prev = accumulate(levels.begin(), levels.begin() + level + 1, 0) + level;
                ans = max(ans, prev);
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}