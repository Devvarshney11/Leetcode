#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

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
ListNode *reverse(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    ListNode *curr = head;
    ListNode *nextptr = head;
    ListNode *prev = 0;
    while (nextptr)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    return prev;
}
void reorderList(ListNode *head)
{
    if (!head || !head->next)
        return;

    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev = nullptr;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    while (fast)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = 0;
    slow = reverse(slow);
    fast = head;

    while (fast && slow)
    {
        ListNode *temp = fast->next;
        fast->next = slow;
        slow = slow->next;
        fast->next->next = temp;
        fast = temp;
    }
}
int main()
{
    return 0;
}