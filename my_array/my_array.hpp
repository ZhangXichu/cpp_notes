template <class T>
class MyArray {

public:
    MyArray(int capacity)
        :_size(capacity),
        _capacity(capacity)
    {
        _data = new T[capacity];
    }
    ~MyArray()
    {
        delete[] _data;
    }

    // subscription operator
    T& operator[] (int index); 
    // remove an element at position i
    void remove(int i);
    // add an element to the end
    void add(T element);
    // insert an element at position i
    void insert(T element, int i);

    void resize(int new_capacity)
    {
        T* data_new = new T[new_capacity];
        int num_to_copy = (new_capacity > _size) ? _size : new_capacity;
        for (int i = 0; i < num_to_copy; i++)
        {
            data_new = _data[i];
        }
        delete[] _data;
        _data = data_new;
        _capacity = new_capacity;
    }

    int get_size() const
    {
        return _size;
    }

    int get_capacity() const
    {
        return _capacity;
    }

private:
    T* _data;
    int _size;
    int _capacity;
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

private:
    int _value;
};

