#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *greater = new ListNode();
        ListNode *head1 = greater;
        ListNode *lesser = new ListNode();
        ListNode *head2 = lesser;
        while (head != 0)
        {
            if (head->val < x)
            {
                lesser->next = head;
                lesser = head;
            }
            else
            {
                greater->next = head;
                greater = head;
            }
            head = head->next;
        }
        lesser->next = head1->next;
        greater->next = 0;
        return head2->next;
    }
};
int main()
{
    return 0;
}