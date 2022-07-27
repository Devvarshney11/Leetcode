#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// By Binary search and two pointer apparoach
vector<int> findClosestElements(vector<int> arr, int x, int k)
{
    int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int l = r - 1;

    while (k--)
    {
        if (r >= arr.size() || l >= 0 && x - arr[l] <= arr[r] - x)
        {
            l--;
        }
        else
            r++;
    }
    return vector<int>(arr.begin() + l + 1, arr.begin() + r);
}

// By two pointer apparoach
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int low = 0;
    int high = arr.size() - 1;

    // In starting the window size is arr.size() and we have to run the loop
    // until the window size is become equal to k
    while (high - low >= k)
    {
        if (x - arr[low] <= arr[high] - x)
            high--;
        else
            low++;
    }
    return vector<int>(arr.begin() + low, arr.begin() + high + 1);
}

// By priority queue
vector<int> findClosestElements(vector<int> &nums, int k, int x)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<pair<int, int>> pq; // Pair of {|a-x|,a}

    for (int i = 0; i < nums.size(); i++)
    {
        if (pq.size() < k)
        {
            pq.push({abs(nums[i] - x), nums[i]});
        }
        else
        {
            if (pq.top().first == abs(nums[i] - x))
            {
                if (pq.top().second > nums[i])
                {
                    pq.pop();
                    pq.push({abs(nums[i] - x), nums[i]});
                }
            }
            else if (pq.top().first > abs(nums[i] - x))
            {
                pq.pop();
                pq.push({abs(nums[i] - x), nums[i]});
            }
        }
    }
    vector<int> ans;

    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end()); // Sort because we in priority queue the elements are stored in max difference order
    return ans;
}

int main()
{
    return 0;
}