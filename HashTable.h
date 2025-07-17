// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include <functional>
#include <string>

template <typename KeyType, typename ValueType>
class HashTable {
private:
    static const int DEFAULT_TABLE_SIZE = 101;
    LinkedList<std::pair<KeyType, ValueType>>* buckets;
    int tableSize;

    int hashFunction(const KeyType& key) const {
        return std::hash<KeyType>{}(key) % tableSize;
    }

public:
    HashTable(int size = DEFAULT_TABLE_SIZE) {
        tableSize = size;
        buckets = new LinkedList<std::pair<KeyType, ValueType>>[tableSize];
    }

    ~HashTable() {
        delete[] buckets;
    }

    void insert(const KeyType& key, const ValueType& value) {
        int bucket = hashFunction(key);
        auto iterator = buckets[bucket].iterator();
        while (iterator.hasNext()) {
            auto& pairItem = iterator.next();
            if (pairItem.first == key) {
                pairItem.second = value;
                return;
            }
        }
        buckets[bucket].insertBack(std::make_pair(key, value));
    }

    ValueType* get(const KeyType& key) {
        int bucket = hashFunction(key);
        auto iterator = buckets[bucket].iterator();
        while (iterator.hasNext()) {
            auto& pairItem = iterator.next();
            if (pairItem.first == key) {
                return &pairItem.second;
            }
        }
        return nullptr;
    }

    bool hasKey(const KeyType& key) {
        return get(key) != nullptr;
    }

    LinkedList<std::pair<KeyType, ValueType>>* getBucketArray() const {
        return buckets;
    }

    int size() const {
        return tableSize;
    }
};

#endif
