//
// Created by Diego Santos Gonzalez on 12/3/23.
//

//Trie was chosen because the time complexity for searching is insane (O(password length)!!!!!!!!!)
#pragma once
#include <iostream>
#include <string>
const int ALPHABET = 95; //this will be changed later. printable ASCII characters 32 to 126. 126-32+1 = 95
const int ASCII_OFFSET = 32; //the range of ASCII characters we care about starts at 32


struct Node{
    Node* children[ALPHABET]; //i know it's a little memory hungry but look at that lovely time complexity
    bool leaf;

    Node();
};

class Trie {
public:
    Trie();
    void insert(std::string password);
    bool search(std::string password);
    static bool allowed(std::string password);


private:
    Node* root;
};