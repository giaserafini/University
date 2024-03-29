#include"stdafx.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


namespace constants {
	 double pi = 3.14;
	 double e = 2.71;
}

using namespace constants;


template <typename T>
class Vector {
private:
	size_t dimensions;
	T* data;
public: 

	Vector<T>(size_t dimensions) :
		dimensions(dimensions), data(new T[dimensions]()) {}
	virtual ~Vector<T>() {
		if (data) delete[] data;
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
	if (&a == &b) return true;
	if (a.size() != b.size())
		return false;
	for (size_t i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}




void zadanie1()
{
	

	try {
		
	
	}
	catch (int e) {
		
		std::cout << "Error code: " << e << endl;
	}
	catch (const std::exception& e) {
	
		std::cout << e.what() << endl;
	}
	
	catch (...) {
		
		std::cout << "Default exception";
	}
}

class no_real_solution : public std::runtime_error {
public:
	no_real_solution() : runtime_error("No real solution!") {}
	virtual  char* what()  throw()
	{
		return "No real solution!";
	}
} no_real_solution;

class binomialsolver {
public:
	int a, b, c, x1, x2;
	binomialsolver() { a = b = c = 0; };
	binomialsolver(int a, int b, int c) { this->a = a;this->b = b;this->c = c; }
	int geta() { return a; }
	int getb() { return b; }
	int getc() { return c; }
	void product() {
		float d;
		d = b*b - 4 * a*c;
		
			if (d < 0)
				std::cout<<no_real_solution.what()<<endl;
			
		else if (d>0)
			{
			std::cout << "delta = " << d << "    delta^1/2 = ";  d = sqrt(d);cout << d << endl;
			float x1 = (-b - d) / 2 * a;
			float x2 = (-b + d) / 2 * a;
			cout << endl << "x = " << x1 << " i " << x2;
			}
		else
			{
			std::cout << "delta = " << d << "    delta^1/2 = ";  d = sqrt(d);cout << d << endl;
			x1 = x2 = (-b) / 2 * a;
			cout << endl << "x = " << x1;
			}
		
	
	}

	void equation(int x) {

		std::cout << a << "x^2 + " << b << "x + " << c << endl;
	}

};


std::ostream& operator << (std::ostream& out,  binomialsolver& bisol) {
	return out << "f(x) = " << bisol.geta() << "x^2 " <<  bisol.getb() << "x " << bisol.getc() ;
}

class fun_lin  {
public:
	double a;
	double b;
	fun_lin() {}
	fun_lin(double &a_,  double &b_) {
		a = a_; b = b_;
	}
	virtual ~fun_lin() {}

	virtual  double get_a()  { return a; }
	virtual  double get_b()  { return b; }
	virtual  double calculate( double &x)  { return (a*x + b); }
};
class sinx  {

public:

	double a;
	double b;

	sinx() {}
	sinx( double &a_,  double &b_) {
		if (a_ == 0) throw std::domain_error("a = 0");
		a = a_; b = b_;
	}
	virtual ~sinx() {}

	virtual  double calculate( double &x)  { return (a*sin(x) + b); }
	virtual double get_a()  { return a; }
	virtual  double get_b()  { return b; }
};
class Cosx  {
public:
	double a;
	double b;

	Cosx() {}
	Cosx( double &a_,  double &b_) {
		if (a_ == 0) throw std::domain_error("a =0");
		a = a_; b = b_;
	}
	virtual ~Cosx() {}

	virtual  double calculate( double &x) { return (a*cos(x) + b); }
	virtual  double get_a()  { return a; }
	virtual  double get_b()  { return b; }
};
class tanx {
public:
	double a;
	double b;

	tanx() {}
	tanx( double &a_, double &b_) {
		if (a_ == 0) throw std::domain_error("a = 0");
		a = a_; b = b_;
	}
	virtual ~tanx() {}

	virtual  double calculate( double &x)  {
		return (a*tan(x) + b);
	}
	virtual  double get_a()  { return a; }
	virtual  double get_b() { return b; }
};
class logx  {
public:
	double a;
	double b;

	logx() {}
	logx( double &a_,  double &b_) {
		if (a_ == 0) throw std::domain_error("a =0");
		a = a_; b = b_;
	}
	virtual ~logx() {}

	virtual  double calculate( double &x)  {
		if (x < 0) throw std::domain_error("x <0");
		if (x == 0) throw std::domain_error("x =0");
		return (a*log(x) + b);
	}
};

void exe2()
{
	binomialsolver bi;
	
	std::cin >> bi.a >> bi.b >> bi.c;
	std::cout <<bi<< endl;

	bi.product();

	int x;
	std::cout << "enter x ";
	std::cin >> x;
	bi.equation(x);

}

void exe3() {
	
	exe2();
}


int main()
{
	exe1();
	exe2();
	exe3();
	return 0;
}










