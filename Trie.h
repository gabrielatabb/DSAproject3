//
// Created by Diego Santos Gonzalez on 12/3/23.
//

//Trie was chosen because the time complexity for searching is insane (O(password length)!!!!!!!!!)

#pragma once
#include <iostream>
#include <string>
const int ALPHABET = 26; //this will be changed later. A-Z, a-z, 0-9, !@#$%&_


struct Node{
    Node* children[ALPHABET];
    bool leaf;

    Node();
};

class Trie {
public:
    Trie();
    void insert(std::string password);
    bool search(std::string password);


private:
    Node* root;
};
