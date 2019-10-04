#include <iostream>

template <typename T>
void swap(T *a, T *b) {
    T ptr = *a;
    *a = *b;
    *b = ptr;
}

template <typename T>
void swap(T ** a, T ** b) {
    T *ptr = *a;
    *a = *b;
    *b = ptr;
}

int main() {
    int a(4), b(5);

    std::cout << a << " " << b << '\n';
    swap<int>(&a,&b);
    std::cout << "Swapped:\n";
    std::cout << a << " " << b << '\n';
    std::cout << std::endl;

    int *A = new int(10);
    int *B = new int(20);

    std::cout << *A << " " << *B << '\n';
    swap<int>(&A,&B);
    std::cout << "Swapped:\n";
    std::cout << *A << " " << *B << '\n';

    return 0;
}