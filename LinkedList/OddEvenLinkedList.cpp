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

ListNode *oddEvenList(ListNode *head)
{
    if (head == 0 || head->next == 0)
        return head;
    ListNode *oddHead = new ListNode(0);
    ListNode *evenHead = new ListNode(0);
    ListNode *oddtail = oddHead;
    ListNode *eventail = evenHead;

    ListNode *temp = head;
    bool flag = 0;
    while (temp != 0)
    {
        if (temp && flag == 0)
        {
            oddtail->next = temp;
            oddtail = temp;
            flag = 1;
            temp = temp->next;
        }
        if (temp && flag == 1)
        {
            eventail->next = temp;
            eventail = temp;
            flag = 0;
            temp = temp->next;
        }
    }
    oddtail->next = evenHead->next;
    eventail->next = 0;
    return oddHead->next;
}
int main()
{
    return 0;
}