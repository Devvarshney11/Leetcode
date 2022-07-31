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

node *detectCycle(node *head)
{
    if (head == 0)
        return head;

    node *slow = head;
    node *fast = head;
    bool flag = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        slow = head;
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    return 0;
}
int main()
{
    return 0;
}