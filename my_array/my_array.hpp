#pragma once

#include <iostream>

template <class T>
class MyArray {

public:
    MyArray(unsigned capacity)
        :_size(capacity),
        _capacity(capacity)
    {
        _data = new T[capacity];  // relies on T having default constructor
    }
    ~MyArray()
    {
        delete[] _data;
    }

    // subscription operator
    T& operator[] (unsigned index)
    {
        return _data[index];
    }

    const T& operator[] (unsigned index) const
    {
        return _data[index];
    }

    operator const T*() const
    {
        return _data;
    }

    operator const T*()
    {
        return _data;
    }

    // add an element to the end
    void add(T element) 
    {
        _size += 1;
        if (_size > _capacity)
        {
            resize(_capacity*2);
        } 
        _data[_size-1] = element;
    }
    void resize(unsigned new_capacity)
    {
        T* data_new = new T[new_capacity];
        unsigned num_to_copy = (new_capacity > _size) ? _size : new_capacity;
        for (unsigned i = 0; i < num_to_copy; i++)
        {
            data_new[i] = _data[i];
        }
        delete[] _data;
        _data = data_new;
        _capacity = new_capacity;
    }

    void update(unsigned n, const T& t)
    {
        if (n >= _capacity)
        {
            throw "Array subscript out of range";
        }
        _data[n] = t;
    }

    // observer
    unsigned get_size() const
    {
        return _size;
    }

    unsigned get_capacity() const
    {
        return _capacity;
    }

    void print() const {
        for (unsigned i = 0; i < _size; ++i) {
            std::cout << _data[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    T* _data;
    unsigned _size;
    unsigned _capacity;
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

