#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string largestPalindromic(string num)
{
    int count[10] = {0};

    for (char ch : num)
    {
        count[ch - '0']++;
    }
    string front;
    for (int i = 9; i >= 0; i--)
    {
        if (i == 0 && front.length() == 0)
            break;
        int t = count[i] / 2;
        while (t--)
        {
            front.push_back(i + '0');
        }
        count[i] = count[i] % 2;
    }
    string ans = front;
    reverse(front.begin(), front.end());
    for (int i = 9; i >= 0; i--)
    {
        if (count[i])
        {
            ans.push_back(i + '0');
            break;
        }
    }
    return ans + front;
}
int main()
{
    return 0;
}