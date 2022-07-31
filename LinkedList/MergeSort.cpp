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
ListNode *Middle(ListNode *head)
{
    ListNode *fast = head->next;
    ListNode *slow = head;

    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}
ListNode *merge(ListNode *head1, ListNode *head2)
{
    if (head1 == 0)
    {
        return head2;
    }
    if (head2 == 0)
    {
        return head1;
    }
    ListNode *ans = 0;
    if (head1->val <= head2->val)
    {
        ans = head1;
        ans->next = merge(head1->next, head2);
    }
    else
    {
        ans = head2;
        ans->next = merge(head1, head2->next);
    }
    return ans;
}
ListNode *mergeSort(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *mid = Middle(head);
    ListNode *second = mid->next;
    mid->next = 0;
    ListNode *left = mergeSort(head);
    ListNode *right = mergeSort(second);
    ListNode *ans = merge(left, right);
    return ans;
}
ListNode *sortList(ListNode *head)
{
    if (head == 0 || head->next == 0)
        return head;

    head = mergeSort(head);
    return head;
}
int main()
{
    return 0;
}