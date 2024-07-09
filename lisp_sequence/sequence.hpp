#pragma once

#include <iostream>

template<class T> class Sequence;

template <class T> 
class SequenceItem {
    friend class Sequence<T>;

    int use_count;
    const T data;
    SequenceItem* next=nullptr;

    SequenceItem(const T& t, SequenceItem* s)
        : use_count(1), data(t), next(s)
    {
        if (s != nullptr)
            s->use_count++;
    }

    SequenceItem(const T& t) : use_count(1), data(t), next(nullptr) {}

    Sequence<T> owntail()
    {
        if (item == 0)
            return 0;
        SequenceItem* i = item;
        SequenceItem** p = &item;

        while (i->use_count == 1) {
            if (i->next == nullptr)
                return i;
            p = &i->next;
            i = i->next;
        }
    }

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
    // copy constructor
    Sequence(const Sequence& s)
        : item(s.item)
    {
        if (item) {
            item->use_count++;
        }
    }

    // construct from built-in array
    Sequence(const T* arr, int n) : item(nullptr) {
        for (int i = n-1; i >= 0; i--) {
            insert(arr[i]);
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

    int length()
    {
        Sequence seq_tl = tl();
        int res = 1;
        while (seq_tl) {
            // seq_tl = seq_tl.tl(); // old way
            // seq_tl++;  // postfix++
            ++seq_tl; // prefix++
            res++;
        }
        return res;
    }


    // return false if Sequence has no elements; true otherwise
    operator bool() const
    {
        return item != nullptr;
    }

    // prefix ++
    Sequence& operator++()
    {
        if (item) {
            SequenceItem<int>* seq_item_ptr = item->next;
            if (seq_item_ptr) 
                seq_item_ptr->use_count++;
            if (--item->use_count == 0)
                delete item;
            item = seq_item_ptr;
        }
        return *this;
    }

    // postfix ++
    Sequence operator++(int) 
    {
        Sequence ret = *this;
        if (item) {
            --item->use_count;
            item = item->next;
            if (item)
                item->use_count++;
        }
        return ret;
    }

    T operator*() const
    {
        return hd();
    }

    Sequence& insert(const T& t)
    {   
        item = new SequenceItem<T>(t, item);
        return *this;
    }

    // observer
    void print_all_elements() const
    {
        SequenceItem<int>* ptr = item; 
        while (ptr != nullptr) {
            std::cout << ptr->get_value() << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }

private:
    SequenceItem<int>* item=nullptr; // head

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


// enable "construct(t, s)" instead of "Sequence<T>(t, s)"
template <class T>
Sequence<T> construct(const T& t, const Sequence<T>& s)
{
    return Sequence<T>(t, s);
}


/**
 * use Sequence for merge sort
*/


template <class T>
Sequence<T> merge(const Sequence<T>& seq_x, const Sequence<T>& seq_y)
{
    // if one sequence is empty, return the other
    if (!seq_x) {
        seq_y.print_all_elements();
        return seq_y; 
    }
    if (!seq_y) {
        return seq_x;
    }  

    // both are non-empty, extract the first element
    T xh = *seq_x;
    T yh = *seq_y;

    // compare
    if (xh < yh)
        return construct(xh, merge(seq_x.tl(), seq_y));

    return construct(yh, merge(seq_x, seq_y.tl()));
}


template<class T> 
void split(Sequence<T> seq_x, Sequence<T>& seq_y, Sequence<T>& seq_z)
{
    while (seq_x) 
    {
        seq_y.insert(seq_x.hd());
        if (++seq_x) {
            seq_z.insert(seq_x.hd());
            ++seq_x;
        }
    }
}

template<class T> 
Sequence<T> sort(const Sequence<T>& x)
{
    if (!x || !x.tl())
        return x;
    
    Sequence<T> p, q;

    split(x, p, q);
    return merge(sort(p), sort(q));
}


