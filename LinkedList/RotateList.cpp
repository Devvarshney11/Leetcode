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
node *rotateRight(node *head, int k)
{
    if (!head || head->next )
    {
        return head;
    }
    node* temp = head;
    int len = 1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        ++len;
    }
    temp->next = head;
    temp = head; 
    for (int i = 0; i < len - (k % len) - 1; ++i)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;
    return head;
}
int main()
{
    return 0;
}