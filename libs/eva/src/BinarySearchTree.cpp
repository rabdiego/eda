#include <iostream>
#include <string>
#include "libs/eva/include/BinarySearchTree.hpp"

using namespace EVA;

// Private methods

template <typename T>
void BinarySearchTree<T>::inOrderPrint(std::shared_ptr<BinaryNode<T>> x, int depth) const {
    if (x) {
        this->inOrderPrint(x->left, depth + 1);
        std::cout << std::string(depth * 4, ' ') << x->value << std::endl;
        this->inOrderPrint(x->right, depth + 1);
    }
}

template <typename T>
std::shared_ptr<BinaryNode<T>> BinarySearchTree<T>::find(const T& value) const {
    std::shared_ptr<BinaryNode<T>> x = this->root;

    while (x) {
        if (x->value == value) {
            return x;
        }

        x = (value < x->value) ? x->left : x->right;
    }

    return nullptr;
}

template <typename T>
void BinarySearchTree<T>::transplant(std::shared_ptr<BinaryNode<T>> u, std::shared_ptr<BinaryNode<T>> v) {
    std::shared_ptr<BinaryNode<T>> uParent = u->parent.lock();

    if (!uParent) {
        this->root = v;
    } else if (u == uParent->left) {
        uParent->left = v;
    } else {
        uParent->right = v;
    }

    if (v) {
        v->parent = u->parent;
    }
}

template <typename T>
std::shared_ptr<BinaryNode<T>> BinarySearchTree<T>::minimum(std::shared_ptr<BinaryNode<T>> x) const {
    while (x->left) {
        x = x->left;
    }
    return x;
}

template <typename T>
std::shared_ptr<BinaryNode<T>> BinarySearchTree<T>::maximum(std::shared_ptr<BinaryNode<T>> x) const {
    while (x->right) {
        x = x->right;
    }
    return x;
}

template <typename T>
std::shared_ptr<BinaryNode<T>> BinarySearchTree<T>::successor(std::shared_ptr<BinaryNode<T>> x) const {
    if (x->right) {
        return this->minimum(x->right);
    }

    std::shared_ptr<BinaryNode<T>> y = x->parent.lock();

    while (y && x == y->right) {
        x = y;
        y = x->parent.lock();
    }

    return y;
}

template <typename T>
void BinarySearchTree<T>::remove(std::shared_ptr<BinaryNode<T>> z) {
    if (!(z->left)) {
        this->transplant(z, z->right);
    } else if (!(z->right)) {
        this->transplant(z, z->left);
    } else {
        std::shared_ptr<BinaryNode<T>> y = this->successor(z);
        this->transplant(y, y->right);
        y->left = z->left;
        z->left->parent = y;
        y->right = z->right;
        z->right->parent = y;
        this->transplant(z, y);
    }
    this->size--;
}

template <typename T>
void BinarySearchTree<T>::clear(std::shared_ptr<BinaryNode<T>> x) {
    if (!x) return;

    this->clear(x->left);
    this->clear(x->right);
    x.reset();
}

// Public methods

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    this->size = 0;
    this->root = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
    std::shared_ptr<BinaryNode<T>> newNode = std::make_shared<BinaryNode<T>>(value);

    std::shared_ptr<BinaryNode<T>> y = nullptr;
    std::shared_ptr<BinaryNode<T>> x = this->root;

    while (x) {
        y = x;
        x = (newNode->value < x->value) ? x->left : x->right;
    }

    if (!y) {
        this->root = newNode;
    } else if (newNode->value < y->value) {
        y->left = newNode;
        newNode->parent = y;
    } else {
        y->right = newNode;
        newNode->parent = y;
    }

    this->size++;
}

template <typename T>
bool BinarySearchTree<T>::remove(const T& value) {
    std::shared_ptr<BinaryNode<T>> aux = this->find(value);
    if (aux) {
        this->remove(aux);
        return true;
    }
    return false;
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& value) const {
    std::shared_ptr<BinaryNode<T>> x = this->find(value);
    if (x) {
        return true;
    }
    return false;
}

template <typename T>
size_t BinarySearchTree<T>::getSize() const {
    return this->size;
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const {
    return (this->size == 0);
}

template <typename T>
void BinarySearchTree<T>::clear() {
    this->clear(this->root);
    this->root.reset();
    this->size = 0;
}

template <typename T>
void BinarySearchTree<T>::print() const {
    std::shared_ptr<BinaryNode<T>> x = this->minimum(this->root);
    
    while (x) {
        std::cout << x->value << " ";
        x = this->successor(x);
    }

    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::printTree() const {
    this->inOrderPrint(this->root, 0);
}

template class BinarySearchTree<int>;
template class BinarySearchTree<float>;
template class BinarySearchTree<double>;