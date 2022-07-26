#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int hIndex(vector<int> &citations)
{
    sort(citations.begin(),citations.end());
    int n = citations.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (citations[mid] == n - mid)
            return citations[mid];
        else if (citations[mid] > n - mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return n - low;
}

int main()
{
    return 0;
}