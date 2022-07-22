#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<int> plusOne(vector<int> &digits)
{
    int carry = 1;
    int n = digits.size();
    reverse(digits.begin(), digits.end());
    for (int i = 0; i < n; i++)
    {
        int sum = digits[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        digits[i] = sum;
        if (carry == 0)
        {
            break;
        }
    }
    while (carry)
    {
        digits.push_back(carry % 10);
        carry = carry / 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}
int main()
{
    return 0;
}