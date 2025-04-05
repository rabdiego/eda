#include <iostream>
#include "libs/eva/include/BinaryNode.hpp"

using namespace EVA;

template <typename T>
BinaryNode<T>::BinaryNode(const T& value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

template <typename T>
void BinaryNode<T>::print() {
    std::cout << this->value << std::endl;
}

template class BinaryNode<int>;
template class BinaryNode<float>;
template class BinaryNode<double>;