#include <iostream>
#include <memory>
#include "libs/eva/include/RedBlackTree.hpp"
#include "libs/eva/include/RedBlackNode.hpp"

int main() {
    std::shared_ptr<EVA::RedBlackInternalNode<int>> node = std::make_shared<EVA::RedBlackInternalNode<int>>(3);
    std::shared_ptr<EVA::RedBlackInternalNode<int>> node2 = std::make_shared<EVA::RedBlackInternalNode<int>>(5);
    std::shared_ptr<EVA::RedBlackExternalNode> null_node = std::make_shared<EVA::RedBlackExternalNode>();
    
    node->parent = node2;
    node->left = null_node;
    node->right = null_node;
    node2->left = node;
    node2->right = null_node;
    node->parent.lock()->print();
    return 0;
}