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

void removeDuplicate(node *&head)
{
     node *temp = head;

     while(temp != 0)
     {
        if(temp->val == temp->next->val)
        {
            node *nextptr = temp->next->next;
            delete temp->next;
            temp->next = nextptr;
        }
        else
        {
            temp = temp->next;
        }
     }
}
int main()
{
    return 0;
}