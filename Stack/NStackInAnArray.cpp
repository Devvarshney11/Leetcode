#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class NStack
{
    int *arr;   //for stack
    int *next;  //for next empty space and for previous top
    int *top;   //for Storing top of the stacks
    int s;
    int n;
    int freespot;     //Store the freespot in the array

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        next = new int[s];
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (freespot == -1)  
            return false;         //Overflow condition
        int index = freespot;     
        freespot = next[index];   //Updating freespot with next empty space
        next[index] = top[m - 1]; //Updating next[index] with previous top index
        top[m - 1] = index;       //Updating top array
        arr[index] = x;           //Inserting the element
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return -1;              //underflow condition
        }
        int index = top[m - 1];     
        top[m - 1] = next[index];   //udating top with prev top stored in next[index]
        next[index] = freespot;     //updating next with next freespace
        freespot = index;           //updating freespot with present index because it also become free
        return arr[index];          //returning ans;
    }
};
int main()
{
    return 0;
}