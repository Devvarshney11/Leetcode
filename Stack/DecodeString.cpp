#include <iostream>
#include <string>

using namespace std;

string decode(string s, int &i)
{
    string ans = "";
    int val = 0;
    while (i < s.length())
    {
        if (isdigit(s[i]))
        {
            val = val * 10;
            val += (s[i] - '0');
            i++;
            if (i < s.length() && !isdigit(s[i]))
            {
                i++;
                string temp = decode(s, i);
                string str = "";
                while (val--)
                {
                    str += temp;
                }
                ans += str;
                val = 0;
            }
        }
        else if (s[i] == ']')
        {
            i++;
            break;
        }
        else
        {
            ans += s[i];
            i++;
        }
    }
    return ans;
}
string decodeString(string s)
{
    int i = 0;
    return decode(s, i);
}
int main()
{
    return 0;
}