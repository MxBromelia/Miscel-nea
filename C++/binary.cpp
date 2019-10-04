class BinaryTree
{
	private:
		int index;
		BinaryTree *left;
		BinaryTree *right;

	public:
		BinaryTree();
		BinaryTree(int);
		~BinaryTree();

		int insert(int index);
		BinaryTree* search(int index);
		int remove(int index);
};

BinaryTree::BinaryTree()
{
	left = nullptr;
	right = nullptr;
}

BinaryTree::BinaryTree(int index)
{
	this->index = index;
	left = nullptr;
	right = nullptr;
}

BinaryTree::~BinaryTree()
{

}

int BinaryTree::insert(int index)
{
	binaryTree* bt = search(index);

	if(bt->index == index)
		return 0;
	else if(bt->index > index)
		left = 
}

BinaryTree* BinaryTree::search(int index)
{
	if(this->index > index && left!=nullptr)
		return left->search(index);
	else if(this->index < index && right!=nullptr)
		return right->search(index);
	else
		return this;
}

int BinaryTree::remove(int index)
{

}

int main()
{
	BinaryTree bt;
	return 0;
}