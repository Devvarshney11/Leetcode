/* Given two integer arrays arr1 and arr2, and the integer d,
 * return the distance value between the two arrays.

 * The distance value is defined as the number of elements arr1[i]
 * such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isValid(vector<int> arr, int val, int d)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (abs(val - arr[mid]) <= d)
        {
            return false;
        }
        else if (arr[mid] > val)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}
int findDistanceValue(vector<int> arr1, vector<int> arr2, int d)
{
    sort(arr2.begin(), arr2.end());
    int count = 0;
    for (auto x : arr1)
    {
        if (isValid(arr2, x, d))
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