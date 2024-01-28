#pragma once

template <class T> class MyArray;
template <class T> class Pointer;

/**
 * @brief class which wraps the data, not exposed to the user
 * 
 * @tparam T 
 */
template<class T> 
class ArrayData
{
    friend class MyArray<T>;
    friend class Pointer<T>;

    T* _arr_data;
    unsigned _size;
    unsigned _capacity;
    int _use_counts;

    ArrayData(unsigned size = 0):
        _arr_data(new T[size]), _size(size), _capacity(size), _use_counts(1) {}
    ~ArrayData() 
    {
        delete [] _arr_data;
    }

    const T& operator[](unsigned n) const 
    {
        if (n >= _size)
        {
            throw "Array subscription out of range";
        }
        return _arr_data[n];
    }

    T& operator[](unsigned n) {
        if (n >= _size) {
            throw "Array subscript out of range";
        }
        return _arr_data[n];
    }

    void resize(unsigned new_capacity)
    {
        T* data_new = new T[new_capacity];
        unsigned num_to_copy = (new_capacity > _size) ? _size : new_capacity;
        for (unsigned i = 0; i < num_to_copy; i++)
        {
            data_new[i] = _arr_data[i];
        }
        delete[] _arr_data;
        _arr_data = data_new;
        _capacity = new_capacity;
    }

    void add(T element) 
    {
        _size += 1;
        if (_size > _capacity)
        {
            resize(_capacity*2);
        } 
        _arr_data[_size-1] = element;
    }

    void print() const {
        for (unsigned i = 0; i < _size; ++i) {
            std::cout << _arr_data[i] << " ";
        }
        std::cout << std::endl;
    }

    // unimplemented, no copies allowed
    ArrayData(const ArrayData&);
    ArrayData& operator=(const ArrayData&);
};