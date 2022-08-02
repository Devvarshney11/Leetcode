#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string removeDuplicates(string s)
{
    int stck = -1;
    int i = 0;
    while (i < s.length())
    {
        if (stck == -1 || s[stck] != s[i])
        {
            stck++;
            s[stck] = s[i];
            i++;
        }
        else
        {
            stck--;
            i++;
        }
    }
    string ans = "";
    for (i = 0; i <= stck; i++)
    {
        ans += s[i];
    }
    return ans;
}

int main()
{
    return 0;
}