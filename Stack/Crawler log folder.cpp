#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int minOperations(vector<string> &logs)
{
    int count = 0;
    for (auto s : logs)
    {
        if (s == "../")
        {
            count = max(0, count - 1);
        }
        else if (s != "./")
        {
            count++;
        }
    }
    return count;
}

int main()
{
    return 0;
}