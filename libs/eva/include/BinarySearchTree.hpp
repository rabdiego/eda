#include <memory>
#include "libs/eva/include/Collection.hpp"
#include "libs/eva/include/BinaryNode.hpp"

#ifndef BinarySearchTree_H
#define BinarySearchTree_H

namespace EVA {
    template <typename T>
    class BinarySearchTree : public Collection<T> {
    private:
        size_t size;
        std::shared_ptr<BinaryNode<T>> root;
        void inOrderPrint(std::shared_ptr<BinaryNode<T>> x, int depth) const;
        void transplant(std::shared_ptr<BinaryNode<T>> u, std::shared_ptr<BinaryNode<T>> v);
        std::shared_ptr<BinaryNode<T>> find(const T& value) const;
        std::shared_ptr<BinaryNode<T>> minimum(std::shared_ptr<BinaryNode<T>> x) const;
        std::shared_ptr<BinaryNode<T>> maximum(std::shared_ptr<BinaryNode<T>> x) const;
        std::shared_ptr<BinaryNode<T>> successor(std::shared_ptr<BinaryNode<T>> x) const;
        void remove(std::shared_ptr<BinaryNode<T>> z);
        void clear(std::shared_ptr<BinaryNode<T>> x);
    
    public:
        BinarySearchTree();
        void insert(const T& value) override;
        bool remove(const T& value) override;
        bool contains(const T& value) const override;
        size_t getSize() const override;
        bool isEmpty() const override;
        void clear() override;
        void print() const override;
        void printTree() const;
    };
};

#endif