#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
string FirstNonRepeating(string A)
{
    // Step 1 : Create a data structure for storing count of characters
    unordered_map<char, int> count;
    string ans = "";
    // Step 2 : Create a data structur for storing characters of string and giving
    //          a first non repeating character
    queue<char> q;

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // Step 3 : Store the count of character
        count[ch]++;

        // Step 4 : push ch in queue;
        q.push(ch);

        // Step 5 : check whether the character at front is repeating or not
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // char at front is repeating
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        // if there is no non-repeating character add '#' to ans
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    return 0;
}