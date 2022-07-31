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
node *removeElement(node *head, int val)
{
    node *sentinal = new node(0);
    sentinal->next = head;

    node *previous = sentinal, *curr = head, *toDelete = nullptr;
    while (curr != nullptr)
    {
        if (curr->val == val)
        {
            previous->next = curr->next;
            toDelete = curr;
        }
        else
        {
            previous = curr;
        }

        curr = curr->next;

        if (toDelete != nullptr)
        {
            delete toDelete;
            toDelete = nullptr;
        }
    }

    node *ret = sentinal->next;
    delete sentinal;
    return ret;
}
int main()
{
    return 0;
}