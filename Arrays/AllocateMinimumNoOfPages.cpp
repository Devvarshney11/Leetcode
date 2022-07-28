#include <iostream>
#include <climits>

using namespace std;

bool isValid(int A[], int N, int M, int mid)
{
    int sum = 0;
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
int findPages(int A[], int N, int M)
{
    int low = INT_MIN;
    int high = 0;

    for (int i = 0; i < N; i++)
    {
        high += A[i];
        if (A[i] > low)
        {
            low = A[i];
        }
    }
    int ans = -1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        if (isValid(A, N, M, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    return 0;
}
