#include <memory>
#include "libs/eva/include/Collection.hpp"
#include "libs/eva/include/RedBlackNode.hpp"

#ifndef RedBlackTree_H
#define RedBlackTree_H

namespace EVA {
    template <typename T>
    class RedBlackTree : public Collection<T> {
    private:
        std::unique_ptr<RedBlackNode> root;
    public:
        RedBlackTree();
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