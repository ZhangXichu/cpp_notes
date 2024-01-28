#include <iostream>
#include "my_array.hpp"
#include "pointer.hpp"

int main()
{
    MyArray<Dummy> arr(20);

    arr[2] = Dummy(22);
    arr[3] = Dummy(30);
    arr[4] = Dummy(40);

    arr.print();

    return 0;
}