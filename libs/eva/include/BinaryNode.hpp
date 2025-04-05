#include <memory>

#ifndef BinaryNode_H
#define BinaryNode_H

namespace EVA {
    template <typename T>
    class BinaryNode {
    public:
        BinaryNode(const T& value);
        T value;
        std::shared_ptr<BinaryNode> left, right;
        std::weak_ptr<BinaryNode> parent;
        void print();
    };
};

#endif