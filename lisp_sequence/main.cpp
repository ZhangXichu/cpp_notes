#include "sequence.hpp"

;

int main()
{
    Sequence<int> sequence;

    sequence = Sequence<int>(5, sequence);
    sequence = Sequence<int>(6, sequence);
    sequence = Sequence<int>(7, sequence);
    sequence = sequence.construct(8, sequence);
    // use convenience function
    sequence.insert(9);

    sequence.print_all_elements();
    std::cout << "length of sequence = " << sequence.length() << std::endl;

    std::cout << "head of sequence = " << *sequence << std::endl;

    return 0;
}