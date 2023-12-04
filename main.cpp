#include <iostream>
#include <fstream>
#include "Trie.h"

int main(){
    std::ifstream data("100kpasswords.txt");

    if(!data.is_open()){
        std::cout << "file failed to open";
    }

    Trie test;
    test.insert("diego");
    std::cout << test.search("diego") << std::endl;
    std::cout << test.search("gabbysucks") << std::endl;
    return 0;
}