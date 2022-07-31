#include<iostream>

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
bool isCycle(node *head)
{
    node *slow = head;
    node *fast = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    return 0;
}