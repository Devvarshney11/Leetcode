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
node *removeNthFromEnd(node *head, int n)
{
    if (!head->next)
    {
        delete head;
        return 0;
    }
    node *temp1 = head;
    node *temp2 = head;
    node *prev = 0;
    while (n--)
    {
        temp1 = temp1->next;
    }
    while (temp1 != 0)
    {
        prev = temp2;
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    if (prev == 0)
    {
        temp1 = temp2->next;
        delete temp2;
        return temp1;
    }
    prev->next = temp2->next;
    delete temp2;
    return head;
}

int main()
{
    return 0;
}