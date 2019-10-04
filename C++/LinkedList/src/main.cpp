#include <iostream>
#include "linked.hpp"

int main() {
    LinkedList<int> l;
    l.insert(1,0);
    std::cout << l;
    std::cout << "\n";

    l.insert(2,0);
    std::cout << l;
    std::cout << "\n";
}