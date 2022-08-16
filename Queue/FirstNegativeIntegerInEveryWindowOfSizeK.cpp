#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    queue<long long> d;
    vector<long long> ans;

    int i;
    for (i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            d.push(i);
        }
    }
    if (d.size() == 0)
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(A[d.front()]);
    }
    while (i < N)
    {
        if (!d.empty() && i - d.front() >= K)
        {
            d.pop();
        }
        if (A[i] < 0)
        {
            d.push(i);
        }
        if (d.size() == 0)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(A[d.front()]);
        }
        i++;
    }
    return ans;
}
//Without space
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K)
{
    int negativeIndex = 0;
    vector<long long> ans;

    for(int i = K-1;i<N;i++)
    {
        while((negativeIndex<i) && (negativeIndex<=i-K || A[negativeIndex]>0))
        {
            negativeIndex++;
        }
        if(A[negativeIndex]<0)
        {
            ans.push_back(A[negativeIndex]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    return 0;
}