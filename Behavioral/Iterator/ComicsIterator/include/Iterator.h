#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdexcept>

template <typename T>
class Iterator {
    T* begin;
    T* end;
    T* current;
public:
    Iterator(T* b, T* e) : begin(b), end(e), current(b) {}

    T& operator*() { return *current; }
    T operator->() { return *current; }

    Iterator& operator++() {
        if (hasNext()) {
            current++;
            return *this;
        }
        throw std::out_of_range("Iterator out of bounds");
    }

    Iterator& operator--() {
        if (current > begin) {
            current--;
            return *this;
        }
        throw std::out_of_range("Iterator out of bounds");
    }

    bool operator!=(const Iterator& other) const {
        return this->current != other.current;
    }

    bool hasNext() {
        return current != end;
    }
};

#endif