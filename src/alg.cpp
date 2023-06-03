// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int fact(int s) {
    if (s > 1)
      return s * fact(s - 1);
    return 1;
}
std::vector<char> getPerm(const Tree& tree, int s) {
  if (tree.getSize() == 0 || s > fact(tree.getSize()))
        return {};
    if (tree.getCharacter_set() == '*')
        s--;
    std::vector<char> r;
    int t = fact(tree.getSize() - 1);
    r.push_back(tree[s / t].getCharacter_set());
    std::vector<char> c = getPerm(tree[s / t], s % t);
    r.insert(r.end(), c.begin(), c.end());
    return r;
}
