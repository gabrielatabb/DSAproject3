#include <fstream>
#include <forward_list>

class hashMap {
    int capacity;
    int size;
    float loadFactor = 0.75f;
    std::ifstream data;
    std::unordered_map<int, std::forward_list<std::string>> hashTable;
public:
    hashMap();
    void resize();
    int hash(std::string key);
    void insert(std::string dataPoint);
};
