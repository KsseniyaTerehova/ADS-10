// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class Tree {
 public:
    explicit Tree(const std::vector<char>& r) {
        option = new Node;
        option->character_set = '*';
        produce(r);
    }
    Tree& operator[](int k) const {
        return *option->options[k];
    }
    char getCharacter_set() const {
        return option->character_set;
    }
    int getSize() const {
        return option->options.size();
    }

 private:
    struct Node {
    char character_set;
    std::vector<Tree*> options;
    };
    Node* option;
    explicit Tree(char character_set) {
        option = new Node;
        option->character_set = character_set;
    }
    void produce(const std::vector<char>& r) {
        for (int n = 0; n < r.size(); n++) {
            std::vector<char> t = r;
            option->options.push_back(new Tree(t[n]));
            t.erase(t.begin() + n);
            option->options[n]->produce(t);
        }
    }
 };
#endif  // INCLUDE_TREE_H_
