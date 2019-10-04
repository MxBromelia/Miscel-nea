#include<iostream>

using namespace std;

class Rect
{
	public:
		float width;
		float height;

		Rect();
		Rect(float);
		Rect(float,float);

		Rect(const Rect &obj);

		~Rect();

		float area();

		friend float perimeter(Rect);
};

//Constructors
Rect::Rect()
{
	width = 0;
	height = 0;
}

Rect::Rect(float w) : width(w) {}

Rect::Rect(float width, float height)
{
	this->width = width;
	this->height = height;
}


//Copy Constructor
Rect::Rect(const Rect &obj)
{
	cout << "Rect is being copied" << endl;

	width = obj.width;
	height = obj.height;
}

//Destructor
Rect::~Rect()
{
	cout << "Object being destroyed" << endl;
}

//Class Method
float Rect::area()
{
	return width*height;
}

//Friend function of a class
float perimeter(Rect rect)
{
	return 2*rect.width + 2*rect.height;
}


int main()
{
	Rect r;
	Rect s(5,2);
	Rect t(3);
	Rect w = r;

	t.height = 1;

	r.width = 1;
	r.height = 2;

	cout << "The Rectangle 1 area is: " << r.area() << endl;
	cout << "The Rectangle 2 area is: " << s.area() << endl;
	cout << "The Rectangle 3 area is: " << t.area() << endl;

	cout << "The perimeter of Rectagle 1 is: " << perimeter(r) <<endl;

	return 0;
}