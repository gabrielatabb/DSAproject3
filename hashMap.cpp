#include <iostream>
#include "hashMap.h"

hashMap::hashMap() {
    size = 0;
    capacity = 10000; //initial capacity
}

int hashMap::hash(std::string key) {
   long hashCode = 0;

    for(int i = 0; i < key.length(); i++) {
        //multiplying ASCII by powers of 31
        if(int(key[i]) > 31 && int(key[i]) < 126)//doing printable ascii only
            hashCode += int(key[i]) * 31;
        else
            return -1; //does not get inserted
    }

    return hashCode % capacity;
}

void hashMap::insert(std::string dataPoint) {
    int hashIndex = hash(dataPoint) % capacity;
    if(hashIndex != -1) {//making sure only printable data gets inputted to map
        container[hashIndex].push_front(std::make_pair(getASCIISum(dataPoint), dataPoint));
        size++;
    }

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

bool hashMap::compare(std::string userPass) {
    int hashIndex = hash(userPass);

    for(std::pair<long, std::string> val: container[hashIndex]) {
        if(userPass == val.second){
            std::cout << "Your password could be guessed immediately." << std::endl;
            std::cout << "Keep in mind, using longer passwords and special characters can make your password more secure. "
                         "Additionally, avoid using common words." << std::endl;
            return true;
        }
    }
    return false;
}

void hashMap::visualizeHashTable(){
    std::cout << "Hashtable Visualization:" << std::endl;

    for (const auto& entry : container) {
        std::cout << "Bucket " << entry.first << ": ";
        for (const auto& value : entry.second) {
            std::cout << value.first << ": " << value.second << " -> ";
        }
        std::cout << "nullptr" << std::endl;
    }

    std::cout << std::endl;
}

void hashMap::resize() {
    std::unordered_map<int, std::forward_list<std::pair<long, std::string>>> newHashMap(capacity * 2);

    for (auto entry: container) {
        std::forward_list<std::pair<long, std::string>> values = entry.second;

        for(std::pair<long, std::string> val: values){
           int newHash = hash(val.second);
            newHashMap[newHash].push_front(val);
        }
    }
    container.swap(newHashMap);
}