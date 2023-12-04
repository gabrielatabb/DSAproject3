//
// Created by Diego Santos Gonzalez on 12/4/23.
//

#pragma once
#include "Trie.h"

bool DictionaryAttack(std::string password, Trie& dictionary){
    if(dictionary.search(password)) {
        std::cout << "Your password could be guessed immediately." << std::endl;
        std::cout << "Keep in mind, using longer passwords and special characters can make your password more secure. "
                     "Additionally, avoid using common words." << std::endl;
        return 1;
    }
    return 0;
}

void BruteForceAttack(std::string password){
    //IF dictionary attack fails, calculate time to brute force
    //assumes a computer can guess 1e9 passwords per second
    bool lowercase = 0;
    bool uppercase = 0;
    bool numbers = 0;
    bool special = 0;

    for (char c: password) {
        //ASCII VALUES:
        //digits: 48-57
        //special: 32-47, 58-64,91-96, 123-126
        //lowercase a-b: 97-122
        //uppercase A-B: 65-90
        if (c >= 97 && c <= 122)
            lowercase = 1;
        else if (c >= 65 && c <= 90)
            uppercase = 1;
        else if (c >= 48 && c <= 57)
            numbers = 1;
        else if ((c >= 32 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
            special = 1;
    }

    int alphabet = 0;
    if(lowercase)
        alphabet+=26;
    if(uppercase)
        alphabet+=26;
    if(numbers)
        alphabet+=10;
    if(special)
        alphabet+=33;

    double bruteforce = (pow(alphabet,password.length())) / 1e9;

    std::cout << std::fixed;
    std::cout << std::setprecision(1);

    //seconds, minutes (60*60), hours (60*60*24), days (60*60*24*7), weeks(60*60*24*7*4), months(60*60*24*7*4*12), years(31536000)
    if (bruteforce < 60)
        std::cout << "Your password could be guessed in " << bruteforce << " seconds." << std::endl;

    else if (bruteforce < 60 * 60)
        std::cout << "Your password could be guessed in " << bruteforce / 60 << " minutes." << std::endl;

    else if (bruteforce < 60 * 60 * 24)
        std::cout << "Your password could be guessed in " << bruteforce / 60 / 60 << " hours." << std::endl;

    else if (bruteforce < 60 * 60 * 24 * 7)
        std::cout << "Your password could be guessed in " << bruteforce / 60 / 60 / 24 << " days." << std::endl;

    else if (bruteforce < 60 * 60 * 24 * 7 * 4)
        std::cout << "Your password could be guessed in " << bruteforce / 60 / 60 / 24 / 7 << " weeks." << std::endl;

    else if (bruteforce < 60 * 60 * 24 * 7 * 4 * 12)
        std::cout << "Your password could be guessed in " << bruteforce / 60 / 60 / 24 / 7 / 4 << " months."
                  << std::endl;
    else
        std::cout << "Your password could be guessed in " << bruteforce / 60 / 60 / 24 / 7 / 4 / 12 << " years."
                  << std::endl;
}