#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string removeDuplicates(string s, int k)
{
    vector<pair<char, int>> v;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (v.size() == 0 or v.back().first != s[i])
        {
            v.push_back({s[i], 1});
        }
        else
        {
            v.back().second += 1;
            if (v.back().second == k)
                v.pop_back();
        }
    }
    string ans = "";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].second; j++)
            ans += v[i].first;
    }
    return ans;
}

int main()
{
    return 0;
}