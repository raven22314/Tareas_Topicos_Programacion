#pragma once
#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;

template <typename T>
class HashSet {
private:
    vector<forward_list<T>> table;
    size_t capacity;

    size_t HashFunction(const T& key) const {
        return hash<T>{}(key) % capacity;
    }

public:
    HashSet(size_t size) : capacity(size) {
        table.resize(size);
    }

    void Add(const T& key) {
        size_t index = HashFunction(key);
        for (const auto& element : table[index]) {
            if (element == key) {
                cout << "Elemento repetido: " << key << endl;
                return;
            }
        }
        table[index].push_front(key);
    }

    bool Contains(const T& key) const {
        size_t index = HashFunction(key);
        for (const auto& element : table[index]) {
            if (element == key) {
                return true;
            }
        }
        return false;
    }

    void Remove(const T& key) {
        size_t index = HashFunction(key);
        table[index].remove(key);
    }

    void Print() const {
        for (size_t i = 0; i < table.size(); ++i) {
            cout << "Bucket " << i << ": ";
            for (const auto& element : table[i]) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};