// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
int factorial(int n) {
    if (n > 1)
      return n * factorial(n - 1);
    return 1;
}
std::vector<char> getPerm(const Tree& tree, int n) {
    if (tree.getSize() == 0 || n > factorial(tree.getSize()))
        return {};
    if (tree.getCharacter() == '*')
        n--;
    std::vector<char> res;
    int temp = factorial(tree.getSize() - 1);
    res.push_back(tree[n / temp].getCharacter());
    std::vector<char> b = getPerm(tree[n / temp], n % temp);
    res.insert(res.end(), b.begin(), b.end());
    return res;
}
