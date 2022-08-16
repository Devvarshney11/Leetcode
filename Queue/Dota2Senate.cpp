#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// With queue
string predictPartyVictory(string senate)
{
    int r = 0;
    int d = 0;

    queue<char> q;

    for (auto &ch : senate)
    {
        q.push(ch);
    }

    while (q.size() != 1)
    {
        if (q.front() == 'R')
        {
            if (r == 0)
            {
                q.push(q.front());
                q.pop();
                d++;
            }
            else
            {
                while (r && !q.empty() && q.front() == 'R')
                {
                    q.pop();
                    r--;
                }
            }
        }
        else
        {
            if (d == 0)
            {
                q.push(q.front());
                q.pop();
                r++;
            }
            else
            {
                while (d && !q.empty() && q.front() == 'D')
                {
                    q.pop();
                    d--;
                }
            }
        }
        if (d == q.size() || r == q.size())
        {
            break;
        }
    }
    if (q.front() == 'R')
        return "Radiant";
    else
        return "Dire";
}

// Without queue
string predictPartyVictory(string senate)
{
    int count = 0;
    int len = 0;
    while (senate.length() != len)
    {
        string s = "";
        len = senate.length();
        for (int i = 0; i < len; i++)
        {
            if (senate[i] == 'R')
            {
                if (count++ >= 0)
                    s += 'R';
            }
            else
            {
                if (count-- <= 0)
                    s += 'D';
            }
        }
        swap(senate, s);
    }
    if (senate[0] == 'R')
        return "Radiant";
    return "Dire";
}
int main()
{
    return 0;
}