#include <iostream>
#include <memory>
#include "libs/eva/include/BinarySearchTree.hpp"
#include "libs/eva/include/BinaryNode.hpp"

int main() {
    std::shared_ptr<EVA::BinaryNode<int>> node = std::make_shared<EVA::BinaryNode<int>>(3);
    std::shared_ptr<EVA::BinaryNode<int>> node2 = std::make_shared<EVA::BinaryNode<int>>(5);
    
    node->parent = node2;
    node2->left = node;
    node->parent.lock()->print();
    return 0;
}