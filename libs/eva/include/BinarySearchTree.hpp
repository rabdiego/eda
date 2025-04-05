#include <memory>
#include "libs/eva/include/Collection.hpp"
#include "libs/eva/include/BinaryNode.hpp"

#ifndef BinarySearchTree_H
#define BinarySearchTree_H

namespace EVA {
    template <typename T>
    class BinarySearchTree : public Collection<T> {
    private:
        std::unique_ptr<BinaryNode<T>> root;
    public:
        BinarySearchTree();
        void insert(const T& value) override;
        bool remove(const T& value) override;
        bool contains(const T& value) const override;
        size_t size() const override;
        bool isEmpty() const override;
        void clear() override;
        void print() const override;
    };
};

#endif