#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class node
{
public:
    int val;
    node *next;
    node *random;
    node(int val)
    {
        this->val = val;
        next = 0;
        random = 0;
    }
};
node *copyRandomList(node *head)
{
    if (head == 0)
        return 0;
    node *temp = head;

    while (temp != 0)
    {
        node *n = new node(temp->val);
        n->next = temp->next;
        temp->next = n;
        temp = n->next;
    }

    temp = head;

    while (temp != 0)
    {
        if (temp->next != 0)
        {
            temp->next->random = (temp->random) ? temp->random->next : 0;
        }
        temp = temp->next->next;
    }
    temp = head;
    node *copyHead = head->next;
    node *copy = copyHead;

    while (copy != 0 && temp != 0)
    {
        temp->next = temp->next->next;

        if (copy->next != 0)
        {
            copy->next = copy->next->next;
        }

        copy = copy->next;
        temp = temp->next;
    }
    return copyHead;
}
int main()
{
    return 0;
}