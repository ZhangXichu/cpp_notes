#include <iostream>
#include "my_array.hpp"
#include "pointer.hpp"
#include "pointer_to_const.hpp"

int main()
{
    MyArray<Dummy> arr(20);

    arr[2] = Dummy(22);
    arr[3] = Dummy(30);
    arr[4] = Dummy(40);

    arr.print();

    Pointer<Dummy> ptr(arr, 2);
    std::cout << "ptr points to " << *ptr << std::endl;
    std::cout << "Use count of arr is " << ptr.get_use_counts() << std::endl;

    Pointer<Dummy> ptr2(ptr);
    std::cout << "Use count of arr is " << ptr.get_use_counts() << std::endl;

    // self assignment
    ptr2 = ptr2;
    std::cout << "Use count of arr is " << ptr.get_use_counts() << std::endl;

    MyArray<int>* arr_ptr = new MyArray<int>(10);
    Pointer<int> ptr3(*arr_ptr, 4);
    std::cout << "Use count of arr_ptr is " << ptr3.get_use_counts() << std::endl;
    delete arr_ptr;
    *ptr3 = 25;
    std::cout << "arr_ptr is still valid: ptr3 = " << *ptr3 << std::endl;

    const MyArray<Dummy> arr_c(20);

    arr_c.print();
    PointerToConst<Dummy> ptr_c(arr_c, 5);
    std::cout << "Use count of arr_c is " << ptr_c.get_use_counts() << std::endl;

    // assignment
    MyArray<int> arr_s(20);

    arr_s[2] = 20;
    arr_s[3] = 8;
    arr_s[4] = 44;

    MyArray<int> arr_s2(15);

    std::cout << "arr_s2 before assignment" << std::endl;
    arr_s2.print();

    arr_s2 = arr_s;

    std::cout << "Use count of arr_s is " << arr_s.get_use_counts() << std::endl;
    std::cout << "Use count of arr_s2 is " << arr_s2.get_use_counts() << std::endl;

    std::cout << "arr_s2 after assignment" << std::endl;
    arr_s2.print();

    // simulate built-in pointer behavior
    MyArray<int> arr_p(15);
    arr_p.random_init();
    std::cout << "Elements in arr_p:" << std::endl;
    arr_p.print();

    Pointer ptr_p(arr_p, 1);
    std::cout << "*ptr_p = " << *ptr_p << std::endl;
    ptr_p++;
    std::cout << "*ptr_p = " << *ptr_p << std::endl;
    std::cout << "*ptr_p = " << *(ptr_p+=2) << std::endl;
    std::cout << "*ptr_p = " << *(++ptr_p) << std::endl;

    // convert array to pointer
    PointerToConst ptr_add = arr_p + 1;
    std::cout << "*ptr_add = " << *ptr_add << std::endl;

    MyArray<int> arr_const(15);
    arr_const.random_init();


    return 0;
}