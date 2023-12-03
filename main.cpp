#include <iostream>
#include <fstream>
//GABBY LAND

int main(){
    std::ifstream data("100kpasswords.txt");

    if(!data.is_open()){
        std::cout << "file failed to open";
    }
    return 0;
}