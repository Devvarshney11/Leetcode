#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    if (s.size() == 0)
    {
        return 0;
    }
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0;
    int j = 0;
    int child = 0;
    while (i < g.size() && j < s.size())
    {
        if (g[i] <= s[j])
        {
            child += 1;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return child;
}

int main()
{
    return 0;
}