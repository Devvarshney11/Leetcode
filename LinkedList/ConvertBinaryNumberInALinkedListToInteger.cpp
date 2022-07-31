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
node *reverse(node *head)
{
    if (!head || !head->next)
        return head;
    node *prev = 0;
    node *curr = head;
    node *nextItr = head;

    while (nextItr != 0)
    {
        nextItr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextItr;
    }
    return prev;
}
int getDecimalValue(node *head)
{
    head = reverse(head);

    node *temp = head;
    int factor = 1;
    int sum = 0;
    while (temp != 0)
    {
        sum += factor * temp->val;
        factor *= 2;
        temp = temp->next;
    }
    return sum;
}
int main()
{
    return 0;
}