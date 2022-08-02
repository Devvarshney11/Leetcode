#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string simplifyPath(string path)
{
    if (path.length() == 1)
    {
        return "/";
    }
    int i = path.length() - 1;
    int back = 0;
    string ans = "";
    while (i >= 0)
    {
        string temp = "";
        if (path[i] == '/')
        {
            i--;
        }
        while (i >= 0 && path[i] != '/')
        {
            temp = path[i] + temp;
            i--;
        }
        if (temp == "..")
        {
            back++;
        }
        else if (temp == "." || temp == "")
        {
            continue;
        }
        else if (back != 0)
        {
            back--;
        }
        else
        {
            ans = "/" + temp + ans;
        }
    }
    if (ans == "")
    {
        return "/";
    }
    return ans;
}

int main()
{
    return 0;
}