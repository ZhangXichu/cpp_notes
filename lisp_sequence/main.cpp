#include "sequence.hpp"

;

int main()
{
    Sequence<int> sequence;

    sequence = Sequence<int>(5, sequence);
    sequence = Sequence<int>(6, sequence);
    sequence = Sequence<int>(7, sequence);
    sequence = construct(8, sequence);
    // use convenience function
    sequence.insert(9);

    sequence.print_all_elements();
    std::cout << "length of sequence = " << sequence.length() << std::endl;

    std::cout << "head of sequence = " << *sequence << std::endl;

    int arr_1[] = {2, 4, 7, 10, 16, 34, 41, 55, 67, 80};
    int arr_2[] = {1, 4, 7, 13, 26, 35, 40, 81};

    Sequence<int> seq_x(arr_1, 10);
    Sequence<int> seq_y(arr_2, 8);

    return 0;
}