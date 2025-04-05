#include <iostream>
#include <memory>
#include "libs/eva/include/BinarySearchTree.hpp"
#include "libs/eva/include/BinaryNode.hpp"

int main() {
    EVA::BinarySearchTree<int> tree;
    tree.insert(447);
    tree.insert(999);
    tree.insert(228);
    tree.insert(573);
    tree.insert(389);
    tree.insert(770);
    tree.insert(746);
    tree.insert(468);
    tree.insert(176);
    tree.insert(618);
    tree.insert(957);
    tree.insert(289);
    tree.insert(150);
    tree.insert(189);
    tree.insert(684);
    tree.printTree();
    return 0;
}