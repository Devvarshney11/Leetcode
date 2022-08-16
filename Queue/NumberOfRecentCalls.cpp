#include <iostream>
#include <queue>

using namespace std;

class RecentCounter
{
public:
    queue<int> q;
    RecentCounter()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int ping(int t)
    {
        q.push(t);
        while ((t - 3000) > q.front())
        {
            q.pop();
        }
        return q.size();
    }
};

int main()
{
    return 0;
}