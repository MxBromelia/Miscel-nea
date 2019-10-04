#include<iostream>
#include<string>

using namespace std;

template <class T>
class node
{
	private:
		int index;
		T value;
	public:
		node *left;
		node *right;
	public:
		node(int index, T value) : index(index), value(value) {
			left = right = nullptr;
		}

		void order()
		{
			if(left != nullptr) left->order();
			cout << value << endl;
			if(right != nullptr) right->order();
		}


};

template <class T>
void order_tree(node<T> & n)
{
	if(n == nullptr) return;

	order_tree(n->left);
	cout << n.value << endl;
	order_tree(n->right);
}

int main()
{
	node<string> n(5,"Hello World!");

	n.left = new node<string>(3,"Wololo!");
	n.right = new node<string>(7,"Walala!");

	n.order();
	order_tree(&n);

	return 0;
}