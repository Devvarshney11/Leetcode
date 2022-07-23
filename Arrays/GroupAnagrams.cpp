#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<string, vector<string>> m;
    for (auto it : strs)
    {
        string temp = it;
        sort(it.begin(), it.end());
        m[it].push_back(temp);
    }
    vector<vector<string>> ans;
    for (auto value : m)
    {
        ans.push_back(value.second);
    }
    return ans;
}

int main()
{
    return 0;
}