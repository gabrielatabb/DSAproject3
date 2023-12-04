#include <iostream>
#include <fstream>
#include "hashMap.h"
//GABBY LAND

int main(){
    std::ifstream data("100kpasswords.txt");

    if(!data.is_open()){
        std::cout << "file failed to open";
    }

    hashMap hashMap;
    std::string dataPoint;

    while (data){
        data >> dataPoint;
        hashMap.insert(dataPoint);
    }

    //hashMap.visualizeHashTable();

    int option;
    while (option != 2){
    std::cout << "\nChoose an option: \n";
    std::cout << "1 - Enter a password\n";
    std::cout << "2 - Quit\n";
    std::cin >> option;

    if(option == 1){
        std::cout << "Enter a password: ";

        std::string userPass;
        std::cin >> userPass;
        hashMap.compare(userPass);
        }

    }




    return 0;
}