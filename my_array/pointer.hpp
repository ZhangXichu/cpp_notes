#pragma once

#include "array_data.hpp"
#include "my_array.hpp"
#include "pointer_to_const.hpp"

/*
class imitating a pointer
containing subscript and pointer to the corresponding array
*/
template<class T> class Pointer : public PointerToConst<T> {
public:
    Pointer(MyArray<T>& my_array, unsigned sub = 0)
        : PointerToConst<T>(my_array, sub) {}
    
    Pointer() {}

    // https://stackoverflow.com/questions/4643074/why-do-i-have-to-access-template-base-class-members-through-the-this-pointer
    T& operator*() const 
    {
        if (this->_arr_data_ptr == 0)
            throw "dereference unbound Pointer";
        return (*(this->_arr_data_ptr))[this->_sub];
    }
};