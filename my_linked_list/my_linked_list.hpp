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
            value = 0;
            next = NULL;
        }

        Node(int value)
        {
            this->value = value;
            this->next = NULL;
        }
    };

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void add_node(T value)
    {
        Node *tmp = new Node(value);
        tmp->value = value;
        tmp->next = nullptr;

        if (!head) { // empty linked list
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    // TODO: delete, insert

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
    Node* tail;
};