#include <iostream>
#include "hashMap.h"

hashMap::hashMap() {
    capacity = 10;
}

int hashMap::hash(std::string key) {
    int hashIndex = 0;
    for(int i = 0; i < key.length(); i++) {
        //multiplying ASCII by powers of 31
        hashIndex += key[i] * pow(31, key.length() - (i + 1));
    }
    return hashIndex;
}

void hashMap::insert(std::string dataPoint) {
    std::cout << dataPoint << " ";
}
