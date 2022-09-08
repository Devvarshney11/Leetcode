#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    long n = s.length();
    vector<int> prefix(n + 1);
    for (auto it : shifts)
    {
        int i = it[0];
        int j = it[1];
        int d = it[2];
        if (d == 1)
        {
            prefix[i]++;
            prefix[j + 1]--;
        }
        else
        {
            prefix[i]--;
            prefix[j + 1]++;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        prefix[i] = prefix[i] + prefix[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        int increase = (s[i] - 'a' + prefix[i]) % 26;
        increase = (increase + 26) % 26;
        s[i] = 'a' + increase;
    }
    return s;
}

int main()
{
    return 0;
}