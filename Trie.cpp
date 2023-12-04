//
// Created by Diego Santos Gonzalez on 12/3/23.
//

#include "Trie.h"

Node::Node() {
    leaf = 0;
    for(auto& c: children)
        c = nullptr;
}

Trie::Trie() {
    root = new Node();
}

void Trie::insert(std::string password) {
    Node* curr = root;
    for(auto& c: password){
        //relative position
        int i = c - 'a';
        if(!curr->children[i])
            curr->children[i] = new Node();
        curr = curr->children[i];
    }
    curr->leaf = 1;
}

bool Trie::search(std::string password) {
    Node* curr = root;
    for(auto& c: password){
        int i = c - 'a';
        if(!curr->children[i])
            return 0;
        curr = curr->children[i];
    }
    return curr->leaf;
}
