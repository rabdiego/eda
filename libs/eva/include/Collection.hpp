#include <iostream>

#ifndef Collection_H
#define Collection_H

namespace EVA {
    /**
    * @class Collection
    * @brief Abstract class for implementing any data structure
    */
    template <typename T>
    class Collection {
    public:
        virtual ~Collection() = default;
        virtual void insert(const T& value) = 0;
        virtual bool remove(const T& value) = 0;
        virtual bool contains(const T& value) const = 0;
        virtual size_t getSize() const = 0;
        virtual bool isEmpty() const = 0;
        virtual void clear() = 0;
        virtual void print() const = 0;
    };
};

#endif