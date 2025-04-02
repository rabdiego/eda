#include <iostream>
#include "libs/eva/include/RedBlackTree.hpp"

using namespace EVA;

template <typename T>
RedBlackTree<T>::RedBlackTree() {
    std::cout << "AOBA\n";
}

template <typename T>
void RedBlackTree<T>::insert(const T& value) {

}

template <typename T>
bool RedBlackTree<T>::remove(const T& value) {
    return false;
}

template <typename T>
bool RedBlackTree<T>::contains(const T& value) const {
    return false;
}

template <typename T>
size_t RedBlackTree<T>::size() const {
    return 2;
}

template <typename T>
bool RedBlackTree<T>::isEmpty() const {
    return false;
}
template <typename T>
void RedBlackTree<T>::clear() {

}

template <typename T>
void RedBlackTree<T>::print() const {
    std::cout << "laslala\n";
}

template class RedBlackTree<int>;
template class RedBlackTree<float>;
template class RedBlackTree<double>;