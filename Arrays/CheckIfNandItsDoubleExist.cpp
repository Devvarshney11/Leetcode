#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool checkIfExist(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int find = 2 * arr[i];
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == find && mid != i)
                return true;
            else if (arr[mid] > find)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return false;
}
int main()
{
    return 0;
}