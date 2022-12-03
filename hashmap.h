#include <list>
#include <vector>
#include <iostream>
#include "hashitem.h"
using namespace std;

template <typename T>
class HashMap
{
    vector<list<HashItem<T>>> hashArray;
    int size;

public:
    HashMap()
    {
        size = 10;
        hashArray.resize(size);
    }
    int hash(int key)
    {
        int index = key % size;
        return index;
    }
    void insert(int key, T const value)
    {
        int index = hash(key);
        hashArray[index].push_back(HashItem<T>{key, value});
    }
    void printTable()
    {
        for(int i = 0 ; i < size; i++)
        {
            cout << "List at index " << i << " is : ";
            for(HashItem<T> hash : hashArray[i])
            {
                cout << hash.getValue() << " , ";
            }
            cout << endl;
        }
    }
    HashItem<T>* search(int key)
    {
        int index = hash(key);
        for(auto itr = hashArray[index].begin(); itr != hashArray[index].end(); itr++)
        {
            if((*itr).getkey() == key)
            {
                return &(*itr);
            }
        }
        return NULL;
    }
};