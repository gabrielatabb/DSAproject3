#include <iostream>
#include <fstream>
#include "hashMap.h"
#include "Trie.h"
#include "PasswordCracker.h"
using namespace std::chrono;
//GABBY LAND

int main(){

    std::ifstream data("100kpasswords.txt");

    if(!data.is_open()){
        std::cout << "file failed to open";
    }

    //create our two data structures
    Trie commonPasswords;
    //hashMap hashPasswords
    hashMap hashMap;

    std::string dataPoint;

    while (data){
        data >> dataPoint;
        if(Trie::allowed(dataPoint)) {
            commonPasswords.insert(dataPoint);
            hashMap.insert(dataPoint);
        }

    }

    //hashMap.visualizeHashTable();

    int option;
    while (option != 2){
        std::cout << "\nIs your password secure?" << std::endl;
        std::cout << "1 - Enter your password. This will definitely not be stored afterwards. Trust us." << std::endl;
        std::cout << "2 - Quit\n";
        std::cin >> option;

    if(option == 1) {
        std::cout << "\nEnter a password: ";

        std::string userPass;
        std::cin >> userPass;

        std::cout << "\nChecking password security with Hash Map: " << std::endl;
        auto startHash = high_resolution_clock::now();

        if(!hashMap.compare(userPass)){
            BruteForceAttack(userPass);
        }
        auto stopHash = high_resolution_clock::now();
        auto durationHash = duration_cast<microseconds>(stopHash - startHash);
        std::cout << "   Time taken by Hash Map: "
             << durationHash.count() << " microseconds" << std::endl;


        std::cout << "\nChecking password security with a Trie: " << std::endl;
        auto startTrie = high_resolution_clock::now();

        if (!DictionaryAttack(userPass, commonPasswords)) {
            BruteForceAttack(userPass);
        }
        auto stopTrie = high_resolution_clock::now();
        auto durationTrie = duration_cast<microseconds>(stopTrie - startTrie);
        std::cout << "   Time taken by Trie: "
                  << durationTrie.count() << " microseconds" << std::endl;
    }

    }

    return 0;
}