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

    node(int val)
    {
        this->val = val;
        next = 0;
    }
};

int length(node *head)
{
    int l = 0;
    while (head != 0)
    {
        l++;
        head = head->next;
    }
    return l;
}
node *getIntersectionNode(node *headA, node *headB)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l1 = length(headA);
    int l2 = length(headB);
    node *temp1, *temp2;
    if (l1 < l2)
    {
        temp1 = headA;
        headA = headB;
        headB = temp1;
    }
    int diff = abs(l1 - l2);
    temp1 = headA;
    temp2 = headB;
    while (diff--)
    {
        temp1 = temp1->next;
    }
    while (temp1 && temp2)
    {
        if (temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 0;
}
int main()
{
    return 0;
}