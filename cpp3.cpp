#include"stdafx.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>


class square {
public:
	int x_square = 0; int y_square = 0; int z_square = 0;
	square() {
	std::cout << "a square has been created" << endl;
}
 ~square() {
	std::cout << "a square has been deleted" << endl;
}
void printsq() {
	std::cout << x_square << " ";
	std::cout << y_square << " ";
	std::cout << z_square << " ";
}
double areasq() { return x_square*x_square; }
};

class rectangular : public square { 
private:
	int x_rec;
	 protected:
		int y_rec;
public:
	int z_rec;
	
	rectangular(int x) : square(), x_rec(x), y_rec(0), z_rec(0) {
		std::cout << "a rectangular has been craeted" << endl;
	}

		 ~rectangular() {
		std::cout << "a rectangular has been deleted" << endl;
	}
	void print_rectangular() {
		std::cout << y_square << " "; 
		std::cout << z_square << " "; 
		std::cout << x_rectangular << " "; 
		std::cout << y_rectangular << " "; 
		std::cout << z_rectangular << " "; 
	}
	double arearec() { return x_rectangular*y_rectangular; }
};
class shape : protected rectangular {
public:
	int  x_shape=0, y_shape=0, z_shape=0;
	shape(int x) : rectangular(x){
		std::cout << "shape has been created" << endl;
	}
	
		~shape() {
		std::cout << "shape has been deleted" << endl;
	}
	 void printsh() {
		std::cout << y_square << " ";
		std::cout << z_square << " ";
		std::cout << y_rectangular << " ";
		std::cout << z_rectangular<<" ";
		std::cout << x_shape;
	    std::cout << y_shape;
		std::cout << z_shape;
	}

	 double areash() { return x_shape*y_shape*z_shape; }
};


void exe1() {
	double a, b, z;
	std::string n;
	square sq; rec(1) ;shape(1);
	 sq.printsq();
	
}




class cylinder{
public:
	double height = 0;
	cylinder() { 
		std::cout << "new cylinder"<<endl; }
	~cylinder() { 
		std::cout << "cuylinder has been deleted" << endl; }
	double area() {}
	double volume(){  }
};
class circle:cylinder {
public:
	double radius = 0;
	circle() {  
		std::cout << "tnew circle" << endl;}
	~circle() {
		std::cout << "a circle has been deleted" << endl; }
	double area() { return radius*radius * 3.14; }
};



void exe2()
{
	
	cylinder w;
}




class function {
protected:
	function() {};
public:
	float calculate(float x) { return 0; }
	
};
class flinear:function
{
public :
	float a, b;
	float calculate(float x) { return a*x + b; }
	function f;
};

void exe3()
{
	int num = 1;
	int a;

}


int main()
{
	exe1();
	exe2();
	exe3();
	return 0;
}

