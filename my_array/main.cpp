#include <iostream>

#include "my_array.hpp"

int main()
{
    MyArray<Dummy> arr(5);

    std::cout << "init size: " << arr.get_size() << std::endl;
    std::cout << "init capacity: " << arr.get_capacity() << std::endl;

    return 0;
}