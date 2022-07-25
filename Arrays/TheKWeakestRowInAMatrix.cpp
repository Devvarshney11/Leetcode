#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] != b[0])           //If no of ones is not equal 
        return a[0] < b[0];    
    else                        //If no of ones is equal
        return a[1] < b[1];     //Then return small index;
}

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int n = mat[0].size();

    vector<vector<int>> v;   //Space use to store {no of one,row index} pair
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[i][0] == 0)
            v.push_back(vector<int>{0, i});  //If there is no soldier

        else
        {   //finding the last index of 1
            int last = -1;
            int l = 0;
            int h = n - 1;
            while (l <= h)
            {
                int m = l + (h - l) / 2;
                if (mat[i][m] == 1)
                {
                    last = m;
                    l = m + 1;
                }
                else
                {
                    h = m - 1;
                }
            }
            v.push_back(vector<int>{last + 1, i});
        }
    }

    sort(v.begin(), v.end(), cmp);   //sort the vector for finding weakest row at starting

    vector<int> soln;
    for (int i = 0; i < k; i++)
        soln.push_back(v[i][1]);

    return soln;
}

int main()
{
    return 0;
}