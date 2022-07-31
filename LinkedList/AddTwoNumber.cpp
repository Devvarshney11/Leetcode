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

int length(node *head)
{
    int l = 0;
    while (head)
    {
        l++;
        head = head->next;
    }
    return l;
}
void addNo(node *head1, node *head2, int &carry, node *&ans)
{
    if (!head1 || !head2)
    {
        return;
    }
    addNo(head1->next, head2->next, carry, ans);

    int sum = head1->val + head2->val + carry;
    carry = sum / 10;
    node *temp = new node(sum % 10);
    temp->next = ans;
    ans = temp;
}
void addremaining(node *head1, int diff, int &carry, node *&ans)
{
    if (diff == 0)
    {
        return;
    }
    addremaining(head1->next, diff - 1, carry, ans);

    int sum = head1->val + carry;
    carry = sum / 10;
    node *temp = new node(sum % 10);
    temp->next = ans;
    ans = temp;
}

node *addTwoNumbers(node *l1, node *l2)
{
    int len1 = length(l1);
    int len2 = length(l2);

    node *temp;
    if (len2 > len1)
    {
        temp = l1;
        l1 = l2;
        l2 = temp;
    }
    int diff = abs(len1 - len2);
    temp = l1;
    while (diff--)
    {
        temp = temp->next;
    }
    node *ans = 0;
    int carry = 0;
    addNo(temp, l2, carry, ans);
    diff = abs(len1 - len2);
    addremaining(l1, diff, carry, ans);

    while (carry)
    {
        node *temp = new node(carry % 10);
        temp->next = ans;
        ans = temp;
        carry = carry / 10;
    }
    return ans;
}
int main()
{
    return 0;
}