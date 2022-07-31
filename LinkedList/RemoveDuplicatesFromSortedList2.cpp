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

node *deleteDuplicates(node *head)
{
    if (head == 0 || head->next == 0)
    {
        return head;
    }
    node *temp = head;
    node *prev = 0;
    while (temp != 0)
    {
        if (temp->next && temp->val == temp->next->val)
        {
            while (temp->next && temp->val == temp->next->val)
            {
                node *nextptr = temp->next->next;
                delete temp->next;
                temp->next = nextptr;
            }
            if (prev == 0)
            {
                head = temp->next;
                delete temp;
                temp = head;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    return 0;
}