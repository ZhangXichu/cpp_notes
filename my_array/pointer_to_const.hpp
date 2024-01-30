#pragma once

#include "array_data.hpp"
#include "my_array.hpp"

/**
 * @brief class similar to Pointer, but points to a const MyArray
 * 
 * @tparam T 
 */
template<class T> 
class PointerToConst
{
public:
    // different from Pointer:
    // const MyArray<T>& instead of MyArray<T>&
    PointerToConst(const MyArray<T>& my_array, unsigned sub = 0)
        : _arr_data_ptr(my_array._data),
          _sub(sub)
          {
            ++_arr_data_ptr->_use_counts;
          }
    PointerToConst()
        : _arr_data_ptr(0), _sub(0) {}
    ~PointerToConst()
    {
        if (_arr_data_ptr && --_arr_data_ptr->_use_counts == 0)
            delete _arr_data_ptr;
    }

    // copy constructor
    PointerToConst(const PointerToConst<T>& pointer)
        : _arr_data_ptr(pointer._arr_data_ptr), _sub(pointer._sub) 
    {
        if (_arr_data_ptr)
            ++_arr_data_ptr->_use_counts;
    }

    // copy assignment
    PointerToConst& operator=(const PointerToConst<T>& pointer)
    {
        if (pointer._arr_data_ptr)
            ++pointer._arr_data_ptr->_use_counts;
        if (_arr_data_ptr && --_arr_data_ptr->_use_counts == 0)
            delete _arr_data_ptr;
        _arr_data_ptr = pointer._arr_data_ptr;
        _sub = pointer._sub;
        return *this;
    }

    // dereference operator
    const T& operator*() const 
    {
        if (_arr_data_ptr == 0)
            throw "dereference unbound Pointer";
        return (*_arr_data_ptr)[_sub];
    }

    void set_sub(unsigned sub)
    {
        _sub = sub;
    }

    int get_use_counts()
    {
        return _arr_data_ptr->_use_counts;
    }

protected:
    ArrayData<T>* _arr_data_ptr;
    unsigned _sub;

};