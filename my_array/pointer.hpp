#pragma once

#include "array_data.hpp"
#include "my_array.hpp"

/*
class imitating a pointer
containing subscript and pointer to the corresponding array
*/
template<class T> class Pointer {
public:
    Pointer(MyArray<T>& my_array, unsigned sub = 0)
        : _ap(&my_array._data), _sub(sub) {}
    
    Pointer()
        : _ap(0), _sub(0) {}
    ~Pointer()
    {
        if (_ap && --_ap._use_count == 0)
            delete _ap;
    }

    // copy constructor
    Pointer(const Pointer<T>& pointer)
        : _ap(pointer._ap), _sub(pointer._sub) 
    {
        if (_ap)
            ++_ap._use_counts;
    }

    // copy assignment
    Pointer& operator=(const Pointer<T>& pointer)
    {
        if (pointer._ap)
            ++pointer._ap->_use_counts;
        if (_ap && --_ap->_use_counts == 0)
            delete _ap;
        _ap = pointer._ap;
        _sub = pointer._sub;
        return *this;
    }

    T& operator*() const // sacrifice safety for convenience
    {
        if (_ap == 0)
            throw "dereference unbound Pointer";
        return (*_ap)[_sub];
    }

    void set_array(MyArray<T>& arr_ref)
    {
        _ap = &arr_ref._data;
    }
    void set_sub(unsigned sub)
    {
        _sub = sub;
    }
    void print_arr()
    {
        _ap._data->print();
    }

private:
    ArrayData<T>* _ap;
    unsigned _sub; 
};