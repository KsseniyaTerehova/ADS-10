// Copyright 2022 NNTU-CS
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int fact(int n) {
    if (n > 1)
      return n * fact(n - 1);
    return 1;
}
std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
    if (tree.getSize() == 0 || n > fact(tree.getSize()))
        return {};
    if (tree.getCharacter_set() == '*')
        n--;
    std::vector<char> resl;
    int temp = fact(tree.getSize() - 1);
    resl.push_back(tree[n / temp].getCharacter_set());
    std::vector<char> b = getPerm(tree[n / temp], n % temp);
    resl.insert(resl.end(), b.begin(), b.end());
    return resl;
