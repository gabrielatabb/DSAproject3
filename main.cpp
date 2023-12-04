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

    std::cout << "Enter a password: ";

    std::string userPass;
    std::cin >> userPass;

    hashMap.compare(userPass);


    return 0;
}