#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int minNumberOfHours(int ie, int ix, vector<int> &energy, vector<int> &experience)
{
    int n = energy.size();
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (ie <= energy[i])
        {
            time += abs(ie - energy[i]) + 1;
            ie += abs(ie - energy[i]) + 1;
        }
        if (ix <= experience[i])
        {
            time += abs(ix - experience[i]) + 1;
            ix += abs(ix - experience[i]) + 1;
        }
        ie -= energy[i];
        ix += experience[i];
    }
    return time;
}

int main()
{
    return 0;
}