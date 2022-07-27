#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

class Solution
{
    private:
    vector<int> range;
    vector<vector<int>> rects;
    
    int area(vector<int> &r)
    {
        return (r[2]-r[0]+1)*(r[3]-r[1]+1);
    }
    
    public:
    Solution(vector<vector<int>> &rectangle)
    {
        rects = rectangle;

        range.push_back(area(rects[0]));
        for(int i = 1;i<rects.size();i++)
        {
            range.push_back(range.back()+area(rects[i]));
        }
    }
    vector<int> pick()
    {
        int random = rand()%range.back();

        int idx = upper_bound(range.begin(),range.end(),random)-range.begin();
        
        auto r = rects[idx];

        int x = rand()%(r[2]-r[0]+1)+r[0];
        int y = rand()%(r[3]-r[1]+1)+r[1];
        
        return {x,y};
    }
};
int main()
{
return 0;
}