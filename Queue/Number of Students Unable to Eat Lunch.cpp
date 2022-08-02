#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    queue<int> q(deque<int>(students.begin(), students.end()));
    int index = 0;
    int cnt = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr != sandwiches[index])
            cnt++, q.push(curr);
        else
            cnt = 0, index++;
        if (cnt == q.size())
            break;
    }
    return q.size();
}

int main()
{
    return 0;
}