#include <iostream>
#include <fstream>

int main(){
    std::ifstream data("100k-most-used-passwords-NCSC.txt");

    if(!data.is_open()){
        std::cout << "file failed to open";
    }
    return 0;
}