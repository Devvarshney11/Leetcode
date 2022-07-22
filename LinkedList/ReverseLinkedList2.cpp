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
    ListNode()
    {
        val = 0;
        next = 0;
    }
    ListNode(int x) 
    {
        val = x;
        next = 0;
    } 
    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
    }
};
ListNode *reverse(ListNode *head, int i, int count, ListNode *&nextptr)
{
    if (head == NULL)
    {
        return head;
    }
    if (i == count)
    {
        nextptr = head->next;
        return head;
    }
    ListNode *second = head->next;
    head->next = 0;
    ListNode *res = reverse(second, i + 1, count, nextptr);
    second->next = head;
    return res;
}
ListNode *MainFunc(ListNode *head, int i, int left, int right)
{
    if (head == 0)
    {
        return head;
    }
    if (i == left)
    {
        ListNode *nextptr = 0;
        ListNode *temp = reverse(head, 1, (right - left + 1), nextptr);
        head->next = nextptr;
        return temp;
    }
    head->next = MainFunc(head->next, i + 1, left, right);
    return head;
}
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    return MainFunc(head, 1, left, right);
}
int main()
{
    return 0;
}