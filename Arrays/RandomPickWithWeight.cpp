#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
class Solution
{
     vector<int> range;

     public:
     Solution(vector<int> &w)
     {
        range.push_back(w[0]);

        for(int i = 1;i<w.size();i++)
        {
            range.push_back(w[i]+range.back());
        }
     }
     int pick()
     {
        int random = rand()%range.back();

        return upper_bound(range.begin(),range.end(),random)-range.begin();
     }
};
int main()
{
return 0;
}