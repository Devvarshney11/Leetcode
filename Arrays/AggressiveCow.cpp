#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isValid(vector<int> &arr,int n,int c,int mid)
{
	int prev = arr[0];
	int cow = 1;
	for(int i = 1;i<n;i++)
	{
		if(arr[i]-prev>=mid)
		{
			cow++;
            if(cow == c)
		        return true;
			prev = arr[i];
		}
	}
	return  false;
}
int minimumDistance(vector<int> &arr, int n, int c)
{
     sort(arr.begin(),arr.end());

     int low = 0;
     int high = arr[n-1];
     
     int ans = 0;
     while(low<=high)
     {
        int mid = low + (high-low)/2;
        
        if(isValid(arr,n,c,mid))
        {
        	ans = mid;
        	low = mid+1;
        }
        else
        {
        	high = mid-1;
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
        int n;
        int c;
        cin>>n>>c;
        
        vector<int> arr(n);
        for(int i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<minimumDistance(arr,n,c);
    }
    return 0;
}