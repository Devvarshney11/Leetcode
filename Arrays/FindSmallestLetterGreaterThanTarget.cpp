// Given a characters array letters that is sorted in non-decreasing order and a character target,
// return the smallest character in the array that is larger than target.

// Note that the letters wrap around.

// For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size();
    if (target >= letters[n - 1])
    {
        return letters[0];
    }
    int left = 0;
    int right = n;
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        if (letters[mid] > target)
        {
            right = mid;
        }
        else
            left = mid + 1;
    }
    return letters[left % n];
}

int main()
{
    return 0;
}