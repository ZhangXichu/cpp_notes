#include <iostream>
#include <iterator>
#include <cstddef>

template <typename T>
class LinkedList{
public:
    struct Node 
    {
        T value;
        Node* next;
        Node* prev;
    }

    class Iterator {
    public:
        // associated types
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::bidirectional_iterator_tag;

        Iterator& operator++() {

        }

        Iterator& operator->() {

        }
    };
};