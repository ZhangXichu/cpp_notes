#include "my_linked_list.hpp"

int main()
{
    LinkedList<int> linked_list;

    linked_list.add_node(1);
    linked_list.add_node(2);
    linked_list.add_node(3);
    linked_list.add_node(4);
    linked_list.add_node(5);

    std::cout << "Forward iteration: ";
    for(auto it = linked_list.begin(); it != linked_list.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    return 0;
}