#include <iostream>
#include "libs/eva/include/BinarySearchTree.hpp"

using namespace EVA;

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    std::cout << "AOBA\n";
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {

}

template <typename T>
bool BinarySearchTree<T>::remove(const T& value) {
    return false;
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& value) const {
    return false;
}

template <typename T>
size_t BinarySearchTree<T>::size() const {
    return 2;
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const {
    return false;
}
template <typename T>
void BinarySearchTree<T>::clear() {

}

template <typename T>
void BinarySearchTree<T>::print() const {
    std::cout << "laslala\n";
}

template class BinarySearchTree<int>;
template class BinarySearchTree<float>;
template class BinarySearchTree<double>;