#include <iostream>
#include "libs/eva/include/RedBlackNode.hpp"

using namespace EVA;

template <typename T>
RedBlackInternalNode<T>::RedBlackInternalNode(const T& value) {
    this->value = value;
    this->color = RedBlackNode::Color::RED;
    this->left = std::make_shared<RedBlackExternalNode>();
    this->right = std::make_shared<RedBlackExternalNode>();
    this->isExternal = false;
}

template <typename T>
void RedBlackInternalNode<T>::print() {
    std::cout << this->value << std::endl;
}

RedBlackExternalNode::RedBlackExternalNode() {
    this->color = RedBlackNode::Color::RED;
    this->isExternal = true;
}

void RedBlackExternalNode::print() {
    std::cout << "NULL\n";
}

template class RedBlackInternalNode<int>;
template class RedBlackInternalNode<float>;
template class RedBlackInternalNode<double>;