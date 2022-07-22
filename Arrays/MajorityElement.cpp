#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int majorityElement(vector<int> &nums)
{
    int counter = 0, majority;
    for (int it : nums)
    {
        if (!counter)
        {
            majority = it;
        }
        counter += (it == majority) ? 1 : -1;
    }
    return majority;
}
int main()
{
    return 0;
}