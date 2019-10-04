#include "foo.h"

template <typename T>
int foo::Foo<T>::foo() {
	return b;
}

template <typename T>
foo::Foo<T>::Foo(int a): a(a) {}

template <typename T>
foo::Foo<T>::Foo(int a, T b) : a(a), b(b) {}

template class foo::Foo<int>;
template class foo::Foo<double>;