#include <iostream>

class IntArray
{
public:
    IntArray(unsigned);
    ~IntArray();
    int& operator[](unsigned); // code will not work if this function is virtual!
    unsigned size() const;

protected:
    unsigned _arr_size;
    int* data;
};

IntArray::IntArray(unsigned size)
    : _arr_size(size), data(new int[size]){}

IntArray::~IntArray()
{
    delete data;
}

unsigned IntArray::size() const
{
    return _arr_size;
}

int& IntArray::operator[](unsigned n)
{
    if (n >= _arr_size)
    {
        throw "subscription out of range";
    }
    return data[n];
}

// derive class, where the array doesn't need to start from 0
class IntBlock : public IntArray
{
public:
    IntBlock(int low, int high)
        : _low(low), _high(high),
          IntArray(low > high? 0 : high - low + 1) {}
    int& operator[](unsigned n)
    {
        // std::cout << "n = " << n << std::endl;
        // std::cout << "_low " << _low << std::endl;
        return IntArray::operator[](n - _low);
    }
    void init_elements();
private:
    int _low, _high;
};

void IntBlock::init_elements()
{
    for (int i = 0; i < _arr_size; i++)
    {
        data[i] = 0;
    }
}

int sum(IntArray& x)
{
    int res = 0;
    for (int i = 0; i < x.size(); i++)
    {
        std::cout << " x[" << i << "] = " << x[i] << std::endl;
        res += x[i];
    }
    return res;
}

int main()
{
    IntBlock int_block(3, 5);

    int_block[3] = 1;
    int_block[4] = 2;
    int_block[5] = 3;

    std::cout << sum(int_block) << std::endl;

    return 0;
}