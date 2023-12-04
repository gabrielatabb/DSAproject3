#include <iostream>
#include <fstream>
#include "Trie.h"

int main(){
    std::ifstream data("100kpasswords.txt");

    if(!data.is_open()){
        std::cout << "file failed to open";
    }

    Trie commonPasswords;
    commonPasswords.insert("diego");
    std::cout << commonPasswords.search("diego") << std::endl;
    std::cout << commonPasswords.search("gabbysucks") << std::endl;

    std::string pass="";
    while(getline(data, pass)){
        if(Trie::allowed(pass)) {
            commonPasswords.insert(pass);
        }
    }

    std::cout << commonPasswords.search("liverpoolfc") << std::endl;

    return 0;
}