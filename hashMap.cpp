#include <iostream>
#include "hashMap.h"

hashMap::hashMap() {
    capacity = 100; //initial capacity is 10
}

int hashMap::hash(std::string key) {
   long hashCode = 0;

    for(int i = 0; i < key.length(); i++) {
        //multiplying ASCII by powers of 31
        hashCode += int(key[i]) * 31;
    }

    return abs(hashCode) % capacity;
}

void hashMap::insert(std::string dataPoint) {
    int hashIndex = hash(dataPoint) % capacity;
    std::cout << hashIndex << " ";
}
