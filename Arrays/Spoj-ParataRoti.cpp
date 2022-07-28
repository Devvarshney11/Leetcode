#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isValid(vector<int> &r, int p, int mid)
{
    int dish = 0;
    for (int i = 0; i < r.size(); i++)
    {
        int sum = r[i];
        int factor = 2;
        while (sum <= mid)
        {
            dish++;
            sum += factor * r[i];
            factor++;
        }
    }
    if (dish >= p)
        return true;
    return false;
}
int minimumTime(vector<int> &rank, int parata)
{
    int m = *max_element(rank.begin(), rank.end());
    int low = 0;
    int high = (parata * (parata + 1) / 2) * m;

    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isValid(rank, parata, mid))
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
     int t;
    cin>>t;

    while(t--)
    {
        int p;
        cin>>p;
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<minimumTime(arr,p)<<endl;
    }
    return 0;
}