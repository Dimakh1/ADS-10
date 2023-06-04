// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class Tree {
 public:
    explicit Tree(const std::vector<char>& row) {
        option = new Node;
        option->character = '*';
        produce(row);
    }
    Tree& operator[](int n) const {
        return *option->options[n];
    }
    char getCharacter() const {
        return option->character;
    }
    int getSize() const {
        return option->options.size();
    }

 private:
    struct Node {
    char character;
    std::vector<Tree*> options;
    };
    Node* option;
    explicit Tree(char character) {
        option = new Node;
        option->character = character;
    }
    void produce(const std::vector<char>& row) {
        for (int i = 0; i < row.size(); i++) {
            std::vector<char> temp = row;
            option->options.push_back(new Tree(temp[i]));
            temp.erase(temp.begin() + i);
            option->options[i]->produce(temp);
        }
    }
};
#endif  // INCLUDE_TREE_H_
