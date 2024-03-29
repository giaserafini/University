#include"stdafx.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>

template <typename T> 
class Vector{
	private:
		size_t dimensions;
		T* data;
public: 

	Vector<T>(const Vector<T>&) {}
		 Vector<T>& operator=(const Vector<T>&) {}
	operator +(vector<int>&v1, vector<int>&v2) 
	{
		vector<int>v3 = v2;
		for (int i = 0;i < v1.size();i++) v3[i] = v3[i] + v1[i];
		return v3;
	}
	operator==(Vector<int>&v1){}
	operator <<(Vector<int>v1) { for (auto e : ) return e; }


	Vector<T>(size_t dimensions) :
		dimensions(dimensions), data(new T[dimensions]()) {}
	virtual ~Vector<T>() {
		if(data) delete[] data;
	}

		size_t size() const {
		return dimensions;
	}
	T& at(size_t index) {
		return data[index];
	}
	const T& at(size_t index) const {
	 return data[index];
	}
	
};


template<typename T>
 Vector<T> add(const Vector<T>& a, const Vector<T>& b) {
	Vector<T> c(a.size());
	for (size_t i = 0; i < a.size(); i++) {
		c[i] = a[i] + b[i];
	}
	return c;
}
template<typename T>
bool equals(const Vector<T>& a, const Vector<T>& b) {
	if(&a == &b) return true;
	if(a.size() != b.size())
		return false;
	for (size_t i = 0; i < a.size(); i++) {
		if(a[i] != b[i]) return false;
	}
	return true;
}

void exe1() 
{
	typedef int T;
	const size_t d = 10;
	
	for (size_t i = 0; i < d; i++) {
		
	}
	

}




void exe2()
{
	exe1();
	

}






class Square {
public:
	int x_square = 0; int y_square = 0; int z_square = 0;
	Square() {
		
	}
	~Square() {
		
	}
	void printsq() {
		std::cout << x_square << " ";
		std::cout << y_square << " ";
		std::cout << z_square << " ";
	}
	double areasq(int x_square) { return x_square*x_square; }
};

class rec : public Square {
public:
	int x_rec;
	int y_rec;

	int z_rec;

	rec(int x) :Square(), x_rec(x), y_rec(0), z_rec(0) {
		
	}
	~rec() {
		
	}
	void printrec() {
		cout << y_square << " ";
		cout << z_square << " ";
		cout << x_rec << " ";
		cout << y_rec << " ";
		cout << z_rec << " ";
	}
	rec() :Square() {}
	double arearec(double x_rec, double y_rec) { 
		return x_rec*y_rec; 
	}
};

class elipsa {
public:
	double a = 0, b = 0;
	elipsa() { 
	}
	~elipsa() {
	}
	double area(double a, double b) { 
		return a*b * 3.14;
	}
	double volume() {  }
};

class circle :elipsa {
public:
	double radius = 0;
	circle() { 
	~circle() {	
	}
	double area(double radius) { return radius*radius * 3.14; }

class shape : protected rec {
public:
	string nazwa;
	double area;

	shape(int x) : rec(x) {
		
	}

	~shape() {
		
	}
	shape() :rec() {};
};

class shape_container {
public:
	vector<shape> neww;
	shape sh; Square sq; circle c; elipsa e; rec r;
	void addshape(std::string name)
	{
		if (name == "elipsa") {
			int a, b; 
			std::cout << "enter data "; 
			std::cin >> a >> b;
			sh.name = name;
			sh.area = e.area(a, b);
			neww.push_back(sh);
		}
		else if (name == "square") {
			int a; 
			std::cout << "enter data "; 
			std::cin >> a;
			sh.nazwa = name;
			sh.area = sq.areasq(a);
			neww.push_back(sh);
		}
		else if (name == "rec") {
			int a, b; 
			std::cout << "enter data "; 
			std::cin >> a >> b;
			sh.name = name;
			sh.area = r.arearec(a, b);
			neww.push_back(sh);
		}
		else if (name == "circle") {
			int a; 
			std::cout << "enter data "; 
			std::cin >> a;
			sh.nazwa = name;
			sh.area = c.area(a);
			neww.push_back(sh);
		}
		else
			std::cout << "there's no such a thing" << endl;



	}

	
void print()
	{
		for (auto e : neww) { 
			std::cout << "there is " << e.name << " its area is equal " << e.area <<endl; 
		}
	}

	double totalarea()
	{
		double s = 0; for (auto e : neww)s = s + e.area; return s;
	}

	void greaterthan(int x)
	{
		for (auto e : neww)if (e.area>x)
			std::cout << "there's " << e.nazwa << " its area is equal " << e.area << endl;
	}
};

void exe3() {
	double b, z = 1;
	std::string n;
	shape_container cont;

	std::cin >> shape;
	ShapeContainer& operator >>(Shape* shape)
	{
	while (z != 0)
	{
		std::cout << endl  << "0 end / 1 add / 2 cout /" << endl;
		std::cout << " 3 sum of areas / 4 areas that are greater than  " << endl;
		std::cin >> z;

		if (z == 1)
		{
			std::cout << "enter a name  " << endl;
			std::cin >> n;
			cont.addshape(n);
		}

		else if (z == 2)
		{
			cont.display();
		}

		else if (z == 3)
		{
			std::cout << cont.totalarea() << endl;
		}

		else if (z == 4)
		{
			int x; 
			std::cin >> x;
			cont.greaterthan(x);
		}


	}
}

}



int main()
{
	exe1();
	exe2();
	exe3();
	return 0;
}