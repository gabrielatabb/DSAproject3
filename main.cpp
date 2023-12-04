#include <iostream>
#include <fstream>
#include <float.h>
#include "Trie.h"
#include "PasswordCracker.cpp"

int main(){
    std::ifstream data("100kpasswords.txt");

    if(!data.is_open()){
        std::cout << "file failed to open";
    }

    //create our two data structures
    Trie commonPasswords;
    //hashMap hashPasswords;

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
    PasswordCracker::


    else {
        //IF dictionary attack fails, calculate time to brute force
        //assumes a computer can guess 1e9 passwords per second
        bool lowercase = 0;
        bool uppercase = 0;
        bool numbers = 0;
        bool special = 0;

        for (char c: userPass) {
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

        double bruteforce = (pow(alphabet,userPass.length())) / 1e9;
        std::cout << DBL_MAX << std::endl;
        std::cout << bruteforce << std::endl;
        std::cout << INT_MAX << std::endl;

        std::cout << std::fixed;
        std::cout << std::setprecision(1);

        //seconds, minutes (60*60), hours (60*60*24), days (60*60*24*7), weeks(60*60*24*7*4), months(60*60*24*7*4*12), years(31536000)
        if(bruteforce < 60){
            std::cout << "Your password could be guessed in " << bruteforce << " seconds." << std::endl;
        }
        else if (bruteforce < 60*60){
            std::cout << "Your password could be guessed in " << bruteforce/60 << " minutes." << std::endl;
        }
        else if (bruteforce < 60*60*24){
            std::cout << "Your password could be guessed in " << bruteforce/60/60 << " hours." << std::endl;
        }
        else if(bruteforce < 60*60*24*7){
            std::cout << "Your password could be guessed in " << bruteforce/60/60/24 << " days." << std::endl;
        }
        else if(bruteforce < 60*60*24*7*4){
            std::cout << "Your password could be guessed in " << bruteforce/60/60/24/7 << " weeks." << std::endl;
        }
        else if(bruteforce < 60*60*24*7*4*12)
            std::cout << "Your password could be guessed in " << bruteforce/60/60/24/7/4 << " months." << std::endl;
        else
            std::cout << "Your password could be guessed in " << bruteforce/60/60/24/7/4/12 << " years." << std::endl;

        std::cout << alphabet << std::endl;
    }
    return 0;
}