#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    int n = deck.size();
    sort(deck.begin(), deck.end());
    vector<int> ans(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
    }
    int chance = 0;
    int flip = 0;
    while (!q.empty())
    {
        if (flip == 0)
        {
            ans[q.front()] = deck[chance++];
            q.pop();
            flip = 1;
        }
        else
        {
            q.push(q.front());
            q.pop();
            flip = 0;
        }
    }
    return ans;
}
int main()
{
    return 0;
}