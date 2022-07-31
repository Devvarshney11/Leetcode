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
// By iteration

node *reverse(node *head)
{
    if (!head || !head->next)
        return head;

    node *prev = nullptr;
    node *curr = head;
    node *nextptr = head;

    while(nextptr != nullptr)
    {
         nextptr = curr->next;
         curr->next = prev;
         prev = curr;
         curr = nextptr;
    }
    return prev;
}

//By recursion

node *reverse(node *head)
{
    if(!head || !head->next)
        return head;

    node *second = head->next;
    head->next = nullptr;
    
    node *res = reverse(second);

    second->next = head;

    return res;
}
int main()
{
    return 0;
}