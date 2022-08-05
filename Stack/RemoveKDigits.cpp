#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// By string properties
string removeKdigits(string num, int k)
{
    if (num.length() == k)
        return "0";
    string ans;

    for (char ch : num)
    {
        while (k > 0 && ans.size() != 0 && ans.back() > ch)
        {
            ans.pop_back();
            k--;
        }
        if (ch == '0' && ans.size() == 0)
        {
            continue;
        }
        ans.push_back(ch);
    }
    if (k > 0)
    {
        while (k > 0 && ans.size() != 0)
        {
            k--;
            ans.pop_back();
        }
    }
    if (ans.size() == 0)
        return "0";
    return ans;
}
int main()
{
    return 0;
}