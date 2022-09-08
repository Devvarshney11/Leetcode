#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Kqueue
{
    int *front;
    int *rear;
    int *next;
    int freespot;
    int *arr;
    int n;
    Kqueue(int k, int n)
    {
        front = new int[k]{-1};
        rear = new int[k]{-1};
        next = new int[n];
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        freespot = 0;
    }

    void push(int q, int num)
    {
        // overflow condition
        if (freespot == -1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        // generate index
        int index = freespot;
        // update freespot;
        freespot = next[index];

        if (front[q - 1] == -1)
        {
            front[q - 1] = index;
        }
        else
        {
            next[rear[q - 1]] = index;

            next[index] = -1;

            rear[q - 1] = index;
        }
        arr[index] = num;
    }
    void pop(int q)
    {
        // underflow condition
        if (front[q-1] == -1)
        {
            cout<<"Queue underflow"<<endl;
            return;
        }
        int index = front[q-1];
        front[q-1] = next[index];
        next[index] = freespot;
        freespot = index;
    }
};
int main()
{
    return 0;
}