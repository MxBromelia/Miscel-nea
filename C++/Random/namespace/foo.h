#pragma once

namespace foo {
	template <typename T>
	class Foo {
	private:
		int a;
		T b;
	public:
		int foo();
		Foo(int);
		Foo(int,T);
	};
}