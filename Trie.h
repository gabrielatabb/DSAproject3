//
// Created by Diego Santos Gonzalez on 12/3/23.
//

//Trie was chosen because the time complexity for searching is insane (O(key length)!!!!!!!!!)
#pragma once
#include <iostream>
const int ALPHABET_SIZE = 26;

class Trie {

    struct Node{
        Node* children = new Node[ALPHABET_SIZE];
        bool endOfWord = 0;

        Node(){
            for(Node n: children)
                n = nullptr;
        }
    };


};
