#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>
#include <memory>


const double pi = 3.14159265;
const double e = 2.71828183;

class Shape {
protected:
	
	std::string name;

public:
	Shape() {}
	Shape(const std::string &name) { this->name = name; }
	virtual ~Shape() {}
	virtual void setName(const std::string &name) { this->name = name; }
	virtual const double area() const { return 0.0; }
	virtual void print() const { std::cout << name << "\n"; }
	virtual const std::string& getName() const { return name; }
};

class Rectangle : public Shape {
protected:
	
	double width;
	double height;

public:
	
	Rectangle() {}
	Rectangle(const std::string &name, const double &width, const double &height) : Shape(name) {
		this->width = width;
		this->height = height;
	}
	virtual ~Rectangle() {}
	virtual const double area() const { return (width*height); }
	virtual void print() const {
		std::cout << name
			<< "\nWidth: " << width
			<< "\nHeight: " << height << "\n";
	}
	virtual const double getWidth() const { return width; }
	virtual const double getHeight() const { return height; }
};

class Square : public Rectangle {
public:
	Square() {}
	Square(const std::string &name, const double &width) : Rectangle(name, width, width) {}
	virtual ~Square() {}
};

class Ellipse : public Shape {
	double smjAxis; 
	double smnAxis; 

public:
	Ellipse() {}
	Ellipse(const std::string &name, const double &minor, const double &major) : Shape(name) {
		smnAxis = minor;
		smjAxis = major;
	}
	virtual ~Ellipse() {}
	virtual const double area() const { return pi * smjAxis*smnAxis; }
	virtual const double circumference() const {
		return pi * (3 / 2)*((smjAxis + smnAxis) - sqrt(smjAxis*smnAxis));
	}
	virtual void print() const {
		std::cout << name
			<< "\na: " << smjAxis
			<< "\nb: " << smnAxis << "\n";
	}
	virtual const double getA() const { return smjAxis; }
	virtual const double getB() const { return smnAxis; }
};

class Circle : public Shape {
protected:
	
	double radius;

public:
	
	Circle() {}
	Circle(const std::string &name, const double &radius) : Shape(name) { this->radius = radius; }
	virtual ~Circle() {}
	virtual const double area() const { return pi * pow(radius, 2); }
	virtual const double circumference() const { return (2 * pi*radius); }
	virtual void print() const { std::cout << name << "\nPromien: " << radius << "\n"; }
	virtual const double getRadius() const { return radius; }
};

class Cylinder : public Circle {
protected:
	double height;

public:
	Cylinder() {}
	Cylinder(const std::string &name, const double &radius, const double &height) : Circle(name, radius) {
		this->height = height;
	}
	virtual ~Cylinder() {}
	virtual const double area() const { return (Circle::area() * 2 + Circle::circumference()*height); }
	virtual const double volume() const { return Circle::area()*height; }
	virtual void print() const { Circle::print(); std::cout << "\nWyskosc: " << height << "\n"; }
	virtual const double getHeight() const { return height; }
};

class ShapeContainer {
protected:
	
	std::vector<Shape*> container;

public:
	
	ShapeContainer() {}
	ShapeContainer(const std::vector<Shape*> &shp_vec) { container = shp_vec; }
	ShapeContainer(Shape* shp) { container.push_back(shp); }
	virtual ~ShapeContainer() {
		for (Shape* &e : container) { delete e; e = nullptr; }
	}

	virtual const unsigned int size() const { return container.size(); }
	virtual void add(Shape* shp) { container.push_back(shp); }
	virtual const double totalArea() const {
		double result = 0.0;
		for (Shape* e : container) result += e->area();
		return result;
	}
	virtual void displayAll() const {
		std::cout.setf(std::ios::fixed, std::ios::floatfield);
		std::cout.precision(2);
		for (Shape* e : container) std::cout << e->getName() << " area " << e->area() << "\n";
	}
	virtual std::vector<Shape*> getGreaterThan(const double& area) {
		std::vector<Shape*>list;
		for (Shape* e : container) if (e->area() > area) list.push_back(e);
		return list;
	}
	virtual void clear() {
		for (Shape* &e : container) { delete e; e = nullptr; }
	}
	virtual const std::vector<Shape*> getContainer() const { return container; }
	virtual const Shape* getElement(const unsigned int &pos) const { return container[pos]; }
};

void print(const std::vector<Shape*> &vec) {
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(2);
	for (Shape* e : vec) { e->print(); std::cout << "\n"; }
}

void exe1() {
	ShapeContainer container;
	Shape *shp = new Shape("Shape");
	Shape *rctgl = new Rectangle("Rectangle", 10.0, 5.0);
	Shape *sqr = new Square("Square", 3.0);
	Shape *elps = new Ellipse("Elipse", 2.0, 4.0);
	Shape *crcl = new Circle("Circle", 3.5);

	container.add(shp);
	container.add(rctgl);
	container.add(sqr);
	container.add(elps);
	container.add(crcl);

	container.displayAll();
	container.clear();
}

void exe2() {
	
	ShapeContainer container;
	Shape* shp = new Shape("Shape");
	Shape* rctgl = new Rectangle("Rectangle", 10.0, 5.0);
	Shape* sqr = new Square("Square", 3.0);
	Shape* elps = new Ellipse("Elipse", 2.0, 4.0);
	Shape* crcl = new Circle("Circle", 3.5);

	container.add(shp);
	container.add(rctgl);
	container.add(sqr);
	container.add(elps);
	container.add(crcl);

	container.displayAll();
	std::cout << "Total areal: " << container.totalArea();
	std::cout << "Areas greater than 9";
	print(container.getGreaterThan(9.0));
	container.clear();
}

class Function {
public:
	
	Function() {}
	virtual ~Function() {}
	virtual const double oblicz(const double &x) const { return 0.0; }
	virtual const double get_a() const { return 1.0; }
	virtual const double get_b() const { return 0.0; }

};
class LinearFunction : public Function {
protected:
	
	double a;
	double b;

public:
	
	LinearFunction() {}
	LinearFunction(const double &a, const double &b) { this->a = a; this->b = b; }
	virtual ~LinearFunction() {}

	virtual const double get_a() const { return a; }
	virtual const double get_b() const { return b; }
	virtual const double oblicz(const double &x) const { return (a*x + b); }
};
class SinxFunction : public Function {
protected:
	
	double a;
	double b;

public:
	
	SinxFunction() {}
	SinxFunction(const double &a, const double &b) { this->a = a; this->b = b; }
	virtual ~SinxFunction() {}
	virtual const double oblicz(const double &x) const { return (a*sin(x) + b); }
	virtual const double get_a() const { return a; }
	virtual const double get_b() const { return b; }
};
class CosxFunction: public Function {
protected:
	
	double a;
	double b;

public:
	CosxFunction() {}
	CosxFunction(const double &a, const double &b) { this->a = a; this->b = b; }
	virtual ~CosxFunction() {}

	virtual const double calculate(const double &x) const { return (a*cos(x) + b); }
	virtual const double get_a() const { return a; }
	virtual const double get_b() const { return b; }
};
class EFunction : public Function {
protected:

	double a;
	double b;

public:
	
	EFunction() {}
	EFunction(const double &a, const double &b) { this->a = a; this->b = b; }
	virtual ~EFunction() {}

	virtual const double oblicz(const double &x) const { return (a*pow(e, x) + b); }
	virtual const double get_a() const { return a; }
	virtual const double get_b() const { return b; }
};
class onebyx : public Function{
protected:
	
	double a;
	double b;

public:
	
	onebyx() {}
	onebyx(const double &a, const double &b) { this->a = a; this->b = b; }
	virtual ~onebyx() {}

	virtual const double calculate(const double &x) const { return (a*(1 / x) + b); }
	virtual const double get_a() const { return a; }
	virtual const double get_b() const { return b; }
};




void exe3() {
	

	const double a = 2.0, b = -0.5;
	const double x = 6.0;
	const double p1 = -1.0, k1 = pi - 1.0;
	const double p2 = -3.0, k2 = 3.0;
	const double p3 = 0.0000000001, k3 = 10.0;

	
	std::shared_ptr<Function> fsin = std::make_unique<SinxFunction>(a, b);
	std::shared_ptr<Function> fcos = std::make_unique<CosxFunction>(a, b);
	std::shared_ptr<Function> fex = std::make_unique<EFunction>(a, b);
	std::shared_ptr<Function> f1px = std::make_unique<onebyx>(a, b);

	
	

int main() {
	exe1();
	exe2();
	exe3();
	return 0;
}
