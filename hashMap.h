#include <fstream>
#include <forward_list>

class hashMap {
    std::unordered_map<int, std::forward_list<std::string>> hashTable;
public:
    int hash(std::string key);
    hashMap(std::ifstream &data);
};
