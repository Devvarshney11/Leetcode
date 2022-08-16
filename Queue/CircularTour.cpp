#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

class PetrolPump
{
    public:
    int petrol;
    int distance;

    PetrolPump(int p,int d)
    {
        petrol = p;
        distance = d;
    }
};
int tour(PetrolPump *p,int n)
{
    int deficiet = 0;
    int balance = 0;
    int start = 0;
    for(int i = 0;i<n;i++)
    {
        balance += p[i].petrol-p[i].distance;
        if(balance<0)
        {
            deficiet += balance;
            balance = 0;
            start = i+1;
        }
    }
    if(deficiet+balance>=0)
    {
        return start;
    }
    return -1;
}
int main()
{
return 0;
}