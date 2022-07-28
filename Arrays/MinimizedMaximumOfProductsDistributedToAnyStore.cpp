#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;

bool isValid(int n, vector<int> &quantities, int mid)
{
    long count = 0;
    for (int x : quantities)
    {
        if (x <= mid)
        {
            count++;
        }
        else
        {
            int temp = x;
            while (temp > 0)
            {
                count++;
                temp = temp - mid;
            }
        }
    }
    return count <= n;
}
int minimizedMaximum(int n, vector<int> &quantities)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int low = 1;
    int high = *max_element(quantities.begin(), quantities.end());

    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (isValid(n, quantities, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    return 0;
}