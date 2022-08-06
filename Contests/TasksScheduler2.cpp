#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long taskSchedulerII(vector<int> &tasks, int space)
{
    long long day = 0;
    unordered_map<int, long long> mp;
    int i = 0;
    int n = tasks.size();
    while (i < n)
    {
        day++;
        if (mp[tasks[i]] == 0)
        {
            mp[tasks[i]] = day;
            i++;
        }
        else if (mp[tasks[i]] + space < day)
        {
            mp[tasks[i]] = day;
            i++;
        }
        else
        {
            day += mp[tasks[i]] + space - day;
        }
    }
    return day;
}
int main()
{
    return 0;
}