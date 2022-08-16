#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int count = 0;
    int i = 0;
    int n = tickets.size();
    while (tickets[k] != 0)
    {
        if (tickets[i % n] != 0)
        {
            count++;
            tickets[i % n]--;
        }
        i++;
    }
    return count;
}

int main()
{
    return 0;
}