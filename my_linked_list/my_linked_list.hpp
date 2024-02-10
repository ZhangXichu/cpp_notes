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

        Node()
        {
            data = 0;
            next = NULL;
        }

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    }

    // TODO: insert, delete

    class Iterator {
    public:
        // associated types
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::bidirectional_iterator_tag;

        Iterator(Node* node) : m_node(node) {}

        Iterator& operator++() {
            m_node = m_node->next;
            return *this;
        }

        Iterator& operator--() {
            m_node = m_node->prev;
            return *this;
        }

        pointer operator->() {
            return m_node;
        }

        reference operator*() const {
            return *m_node;
        }

    private:
        Node* m_node;
    };

private:
    Node* head;
    Node* tai;
};