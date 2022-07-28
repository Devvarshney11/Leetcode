#include <iostream>
#include <climits>

using namespace std;
bool isValid(int A[], int N, int M, long long mid)
{
    long long sum = 0;
    int count = 1;

    for (int i = 0; i < N; i++)
    {
        sum += A[i];

        if (sum > mid)
        {
            count++;
            sum = A[i];
        }
    }
    return count <= M;
}
long long minTime(int arr[], int n, int k)
{
    long long low = INT_MIN;
    long long high = 0;

    for (int i = 0; i < n; i++)
    {
        high += arr[i];
        if (arr[i] > low)
        {
            low = arr[i];
        }
    }
    long long ans = low;
    while (low <= high)
    {
        long long mid = low + ((high - low) >> 1);

        if (isValid(arr, n, k, mid))
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