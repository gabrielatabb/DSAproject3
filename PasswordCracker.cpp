//
// Created by Diego Santos Gonzalez on 12/4/23.
//
#include <string>
#include "Trie.h"

bool DictionaryAttack(std::string& password, Trie& dictionary){
    if(dictionary.search(password)) {
        std::cout << "Your password could be guessed immediately." << std::endl;
        std::cout << "Keep in mind, using longer passwords and special characters can make your password more secure. "
                     "Additionally, avoid using common words." << std::endl;
    }
}
