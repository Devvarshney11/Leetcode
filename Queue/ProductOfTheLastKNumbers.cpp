#include <iostream>
#include <vector>

using namespace std;

// By prefix product method
class ProductOfNumbers
{
    vector<int> vec;

public:
    ProductOfNumbers()
    {
        vec = {1};
    }

    void add(int num)
    {
        if (num)
            vec.push_back(vec.back() * num);
        else
            vec = {1};
    }

    int getProduct(int k)
    {
        return k < vec.size() ? vec.back() / vec[vec.size() - 1 - k] : 0;
    }
};

int main()
{
    return 0;
}