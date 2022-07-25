/*Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
Example :
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...].
The 5th missing positive integer is 9.*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// This function return the no of missing numbers from 1 to num in range
int compute(int num, int range)
{
    return num - range;
}
int findKthPositive(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        int missing = compute(arr[mid], mid + 1);

        if (missing >= k)
        {
            high = mid - 1; // If count of  missing no is greater than k then decrease range
        }
        else
        {
            low = mid + 1; // If count of missing no is lesser than k then increase range
        }
    }
    // If this case occur
    //  arr = [5,6,7,8,9] and k = 2
    // Then return  k value
    if (high == -1)
    {
        return k;
    }
    return arr[high] + k - compute(arr[high], high + 1);
}

int main()
{
    return 0;
}