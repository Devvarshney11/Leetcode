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

node *merge(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    node *resHead = new node(0);
    node *resTail = resHead;

    while (head1 && head2)
    {
        if (head1->val <= head2->val)
        {
            resTail->next = head1;
            head1 = head1->next;
            resTail = resTail->next;
        }
        else
        {
            resTail->next = head2;
            head2 = head2->next;
            resTail = resTail->next;
        }
    }
    return resHead->next;
}
int main()
{
    return 0;
}