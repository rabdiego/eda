#include <memory>

#ifndef RedBlackNode_H
#define RedBlackNode_H

namespace EVA {
    class RedBlackNode {
    public:
        enum class Color { RED, BLACK };
        Color color;
        bool isExternal;
        virtual void print() = 0;
    };

    template <typename T>
    class RedBlackInternalNode : public RedBlackNode {
    public:
        RedBlackInternalNode(const T& value);
        T value;
        std::shared_ptr<RedBlackNode> left, right;
        std::weak_ptr<RedBlackNode> parent;
        void print() override;
    };

    class RedBlackExternalNode : public RedBlackNode {
    public:
        RedBlackExternalNode();
        void print() override;
    };
};

#endif