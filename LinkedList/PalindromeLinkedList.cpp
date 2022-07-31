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

bool check(node *head1, node *head2)
{
    while (head1 && head2)
    {
        if (head1->val != head2->val)
            return false;
        else
            head1 = head1->next;
        head2 = head2->next;
    }
    if (!head1 && !head2)
        return true;
    return false;
}

node *reverse(node *head)
{
    if (!head || !head->next)
        return head;

    node *prev = nullptr;
    node *curr = head;
    node *nextptr = head;

    while (nextptr != nullptr)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    return prev;
}

bool isPalindrome(node *head)
{
    if (!head || !head->next)
        return true;
    node *fast = head;
    node *slow = head;
    node *prev = nullptr;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    while (fast != 0)
    {
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = 0;
    slow = reverse(slow);
    return check(head, slow);
}
int main()
{
    return 0;
}