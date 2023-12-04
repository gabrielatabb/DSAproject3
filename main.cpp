#include <iostream>
#include <fstream>
#include <float.h>
#include "Trie.h"
#include "PasswordCracker.h"

int main(){
    std::ifstream data("100kpasswords.txt");

    if(!data.is_open()){
        std::cout << "file failed to open";
    }

    //create our two data structures
    Trie commonPasswords;
    //hashMap hashPasswords

    std::string pass="";
    while(getline(data, pass)){
        if(Trie::allowed(pass)) {
            commonPasswords.insert(pass);
            //hashPasswords.insert(pass)
        }
    }

    std::cout << "Is your password secure?" << std::endl;
    std::cout << "Enter your password. This will definitely not be stored afterwards. Trust us." << std::endl;
    std::string userPass;
    getline(std::cin, userPass);

    if(!DictionaryAttack(userPass,commonPasswords)){
        BruteForceAttack(userPass);
    }

    return 0;
}