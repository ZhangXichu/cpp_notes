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
        : _arr_data_ptr(my_array._data), _sub(sub) 
        {
            ++_arr_data_ptr->_use_counts;
        }
    
    Pointer()
        : _arr_data_ptr(0), _sub(0) {}
    ~Pointer()
    {
        if (_arr_data_ptr && --_arr_data_ptr->_use_counts == 0)
            delete _arr_data_ptr;
    }

    // copy constructor
    Pointer(const Pointer<T>& pointer)
        : _arr_data_ptr(pointer._arr_data_ptr), _sub(pointer._sub) 
    {
        if (_arr_data_ptr)
            ++_arr_data_ptr->_use_counts;
    }

    // copy assignment
    Pointer& operator=(const Pointer<T>& pointer)
    {
        if (pointer._arr_data_ptr)
            ++pointer._arr_data_ptr->_use_counts;
        if (_arr_data_ptr && --_arr_data_ptr->_use_counts == 0)
            delete _arr_data_ptr;
        _arr_data_ptr = pointer._arr_data_ptr;
        _sub = pointer._sub;
        return *this;
    }

    T& operator*() const // sacrifice safety for convenience
    {
        if (_arr_data_ptr == 0)
            throw "dereference unbound Pointer";
        return (*_arr_data_ptr)[_sub];
    }

    void set_array(MyArray<T>& arr_ref)
    {
        _arr_data_ptr = &arr_ref._data;
    }
    void set_sub(unsigned sub)
    {
        _sub = sub;
    }
    int get_use_counts()
    {
        return _arr_data_ptr->_use_counts;
    }

private:
    ArrayData<T>* _arr_data_ptr;
    unsigned _sub; 
};