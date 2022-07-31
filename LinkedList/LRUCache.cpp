/*
*Design a data structure that follows the constraints of a Least Recently Used(LRU) cache.
*Implement the LRUCache class :
  **LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
  **int get(int key) Return the value of the key if the key exists,otherwise return -1.
  **void put(int key, int value) Update the value of the key if the key exists.
    Otherwise, add the key - value pair to the cache.
    If the number of keys exceeds the capacity from this operation,
    evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
    int size;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            l.splice(l.begin(), l, m[key]);
            m[key]->second = value;
            return;
        }
        if (l.size() == size)
        {
            auto del = l.back().first;
            l.pop_back();
            m.erase(del);
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};

int main()
{
    return 0;
}