#include <iostream>
#include "hashMap.h"

hashMap::hashMap() {
    size = 0;
    capacity = 10000; //initial capacity, might resize
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
    hashTable[hashIndex].push_front(getASCIISum(dataPoint));
    size++;

    //check if the table needs to be resized
    if( (float)size/capacity > loadFactor){
        resize();
        capacity = capacity * 2;
    }
}

long hashMap::getASCIISum(std::string key) {
    long sum = 0;
    for(int i = 0; i < key.length(); i++) {
        //multiplying ASCII by powers of 31
        sum += int(key[i]);

    }

    return sum;
}

void hashMap::visualizeHashTable(){
    std::cout << "Hashtable Visualization:" << std::endl;

    for (const auto& entry : hashTable) {
        std::cout << "Bucket " << entry.first << ": ";
        for (const auto& value : entry.second) {
            std::cout << value << " -> ";
        }
        std::cout << "nullptr" << std::endl;
    }

    std::cout << std::endl;
}

void hashMap::resize() {

}
