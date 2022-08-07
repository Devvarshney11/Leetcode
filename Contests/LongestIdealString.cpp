#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int longestIdealString(string s, int k)
{
    int l = s.length();
    if (l == 1)
        return 1;
    map<char, long> mp;
    mp[s[0]] = 1;
    long ans = 0;
    for (int i = 1; i < l; i++)
    {
        long best = 1;
        for (auto &it : mp)
        {
            if (abs(it.first - s[i]) <= k)
            {
                best = max(best, it.second + 1);
            }
        }
        mp[s[i]] = best;
        ans = max(ans, best);
    }
    return ans;
}

int main()
{
    return 0;
}