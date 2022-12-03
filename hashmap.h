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
    int PRIME;
    int a;
    int b;

public:
    HashMap()
    {
        PRIME = 7;
        size = 10;
        hashArray.resize(size);
        initializeHashFunction();
    }
    void initializeHashFunction()
    {
        srand(time(0));
        a = (rand() % PRIME) + 1;
        b = rand() % PRIME;
    }
    int hash(int key)
    {
        int index = ((a * key + b) % PRIME) % size;
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
    bool remove(int key)
    {
        int index = hash(key);
        auto toDelete = search(key);
        if(toDelete)
        {
            hashArray[index].remove(*toDelete); 
            return true;
        }  
        else
        {
            return false;
        }
    }

};