#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        next = 0;
    }
};

void sorting(ListNode *&sort, ListNode *n)
{
    if (sort == NULL || n->val < sort->val)
    {
        n->next = sort;
        sort = n;
        return;
    }
    ListNode *temp = sort;
    while (temp->next != 0 && temp->next->val < n->val)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}
ListNode *insertionSortList(ListNode *head)
{
    if (head->next == 0)
        return head;
    ListNode *temp = head;
    ListNode *sort = NULL;
    while (temp != 0)
    {
        ListNode *nextptr = temp->next;
        sorting(sort, temp);
        temp = nextptr;
    }
    return sort;
}
int main()
{
    return 0;
}