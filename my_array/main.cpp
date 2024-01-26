#include <iostream>
#include "my_array.hpp"

int main()
{
    MyArray<Dummy> arr(5);

    arr.add(Dummy(1));
    arr.add(Dummy(2));
    arr.add(Dummy(3));

    std::cout << "Elements in arr :" << std::endl;
    arr.print();


    std::cout << "Elements in arr using conversion operator:" << std::endl;
    const Dummy* ptr = arr; // Implicit conversion to const Dummy*
    std::cout << *(ptr+5) << std::endl;

    std::cout << "current size : " << arr.get_size() << std::endl;
    std::cout << "current capacity : " << arr.get_capacity() << std::endl;

    std::cout << "the 7th element is :" << arr[6] << std::endl;

    return 0;
}