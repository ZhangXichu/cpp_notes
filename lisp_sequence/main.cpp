#include "sequence.hpp"

;

int main()
{
    Sequence<int> sequence;

    sequence = Sequence<int>(5, sequence);
    sequence = Sequence<int>(6, sequence);
    sequence = Sequence<int>(7, sequence);

    sequence.print_all_elements();

    return 0;
}