#pragma once

#include <iostream>

template<class T> class Sequence;

template <class T> 
class SequenceItem {
    friend class Sequence<T>;

    int use_count;
    const T data;
    SequenceItem* next;

    SequenceItem(const T& t, SequenceItem* s)
        : use_count(1), data(t), next(s)
    {
        if (s)
            s->use_count++;
    }
    
    SequenceItem(const T& t) : use_count(1), data(t), next(nullptr) {}

    const T& get_value() {
        return data;
    }
};


template<class T> class Sequence {
public:
    // create and return a sequence with no elements
    Sequence()
        :item(nullptr) {}
    // create and return a sequence with first element t and subsequent elements
    // those of s
    Sequence(const T& t, const Sequence& s):
        item(new SequenceItem<T>(t, s.item)) {}
    // enable "construct(t, s)" instead of "Sequence<T>(t, s)"
    Sequence construct(const T& t, const Sequence& s)
    {
        return Sequence(t, s);
    }
    // copy constructor
    Sequence(const Sequence& s)
    {
        if (item) {
            item->use_count++;
        }
    }
    // copy asssignment
    Sequence& operator=(const Sequence& s)
    {
        if (s.item)
            s.item->use_count++;
        destory(item);  // TODO : implement destory()
        item = s.item;
        return *this;
    }

    ~Sequence()
    {
        destory(item);
    }

    // return the first element of the Sequence, Sequence must have >= 1 elements
    T hd() const
    {
        if (item)
        {
            return item->data;
        } else {
            throw "hd of an empty Seq";
        }
    }
    // create and return a sequence containing all but the first element of Sequence, 
    // Sequence must have >= 1 elements
    Sequence tl() const
    {
        if (item) {
            return Sequence<T> (item->next);
        } else {
            throw "tl of an empty Sequence.";
        }
    }
    // return false if Sequence has no elements; true otherwise
    operator bool() const
    {
        return item != nullptr;
    }

    // observer
    void print_all_elements()
    {
        SequenceItem<int>* ptr = item; 
        while (ptr != nullptr) {
            std::cout << ptr->get_value() << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }

private:
    SequenceItem<int>* item; // head

    Sequence(SequenceItem<int>* s) // used form creating a Sequence from a tail
        : item(s)
        {
            if (s) 
                s->use_count++;
        }

    void destory(SequenceItem<int>* item)
    {
        while (item && --item->use_count == 0)
        {
            SequenceItem<int>* next = item->next;
            delete item;
            item = next;
        }
    }
};


