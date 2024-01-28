#pragma once

#include "array_data.hpp"
#include "my_array.hpp"

/*
class imitating a pointer
containing subscript and pointer to the corresponding array
*/
template<class T> class Pointer {
public:
    Pointer(MyArray<T>& ap, unsigned sub = 0)
        : _ap(&ap), _sub(sub) {}
    Pointer()
        : _ap(0), _sub(0) {}

    T& operator*() const // sacrifice safety for convenience
    {
        if (_ap == 0)
            throw "dereference unbound Pointer";
        return (*_ap)[_sub];
    }

    void set_array(MyArray<T>& arr_ref)
    {
        _ap = &arr_ref;
    }
    void set_sub(unsigned sub)
    {
        _sub = sub;
    }
    void print_arr()
    {
        _ap->print();
    }

private:
    MyArray<T>* _ap;
    unsigned _sub; 
};