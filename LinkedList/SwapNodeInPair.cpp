#include <iostream>

using namespace std;

class node
{
public:
    int val;
    node *next;

    node(int val)
    {
        this->val = val;
        next = 0;
    }
};
node *swapPairs(node *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    node *prev = 0;
    node *curr = head;
    node *nextItr = head;
    int n = 2;
    while (n--)
    {
        nextItr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextItr;
    }
    head->next = swapPairs(curr);
    return prev;
}
int main()
{
    return 0;
}