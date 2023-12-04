#include <iostream>
#include "hashMap.h"

hashMap::hashMap(std::ifstream &data) {
    std::string dataPoint = "";
    while (data){
        data >> dataPoint;
        std::cout << dataPoint << std::endl;
    }
}
