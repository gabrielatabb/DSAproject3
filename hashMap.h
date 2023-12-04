#include <fstream>
#include <forward_list>
#include <utility>

class hashMap {
    long capacity;
    long size;
    float loadFactor = 0.75f;
    std::ifstream data;
    std::unordered_map<int, std::forward_list<std::pair<long, std::string>>> container;
public:
    hashMap();
    void resize();
    void visualizeHashTable();
    int hash(std::string key);
    void compare(std::string userPass);
    void insert(std::string dataPoint);
    long getASCIISum(std::string key);
};
