#pragma once

#include <iostream>

#include "array_data.hpp"

template <class T>
class MyArray {

    friend class Pointer<T>;
    friend class PointerToConst<T>;

public:
    MyArray(unsigned size)
        : _data(new ArrayData<T>(size))
    {}

    ~MyArray()
    {
        if (--_data->_use_counts == 0)
            delete _data;
    }

    // subscription operator
    T& operator[] (unsigned index)
    {
        return (*_data)[index];
    }

    const T& operator[] (unsigned index) const
    {
        return (*_data)[index];
    }

    void resize(unsigned n)
    {
        _data->resize(n);
    }

    // observer
    unsigned get_size() const
    {
        return _data->_size;
    }

    unsigned get_capacity() const
    {
        return _data->_capacity;
    }

    void print() const {
        _data->print();
    }

private:
    ArrayData<T>* _data;

    MyArray(const MyArray&);
    MyArray& operator=(const MyArray&);
};


// dummy object
class Dummy {

public:
    Dummy() : _value(0) {}
    Dummy(int value) : _value(value) {}
    int get_value() const
    {
        return _value;
    }

    friend std::ostream& operator<<(std::ostream& os, const Dummy& dummy) {
        os << dummy._value;
        return os;
    }

private:
    int _value;
};

