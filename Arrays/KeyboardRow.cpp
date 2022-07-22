#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> lineno = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};

bool correct(string st)
{
    int line = lineno[tolower(st[0]) - 'a'];
    for (auto ch : st)
    {
        if (lineno[tolower(ch) - 'a'] != line)
        {
            return false;
        }
    }
    return true;
}
vector<string> findWords(vector<string> &words)
{
    vector<string> ans;
    for (auto &word : words)
    {
        if (correct(word))
        {
            ans.push_back(word);
        }
    }
    return ans;
}
int main()
{
    return 0;
}