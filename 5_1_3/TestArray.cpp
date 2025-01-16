// Test.cpp
//
// A test program (separate source file with a main() function) for the Point class.
// 
// 
// @Author Zehao Yang
// @Version May 18, 2023

#include "Point.hpp"/* Include the point header file.*/
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include "Shape.hpp"
#include <iostream>
#include "OutOfBoundsException.hpp"
#include "ArrayException.hpp"
#include "NumericArray.hpp"
#include "PointArray.hpp"
#include "Stack.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/variant.hpp"
#include "Visitor.hpp"
using namespace std;

using Shape = ZehaoYang::CAD::Shape;
using Line = ZehaoYang::CAD::Line;
using Circle = ZehaoYang::CAD::Circle;
using Point = ZehaoYang::CAD::Point;
using ArrayException = ZehaoYang::Containers::ArrayException;
using OutOfBoundsException = ZehaoYang::Containers::OutOfBoundsException;
using ZehaoYang::Containers::Array;
using ZehaoYang::Containers::NumericArray;
using ZehaoYang::Containers::PointArray;
using ZehaoYang::Containers::Stack;
using ZehaoYang::Containers::StackException;
//namespace ZY = ZehaoYang::CAD;
using ZehaoYang::Containers::Visitor;

typedef boost::variant<Point, Line, Circle> ShapeType;

ShapeType CreateShape();


int main() {
	/*Call CreateShape() function and print the result by sending it to cout. */
	ShapeType myVariant = CreateShape();
	cout << myVariant << endl;

	/*Assign the variant to a Line variable by using the global boost:get<Line>() function.*/
	Line myLine;
	try
	{
		myLine = boost::get<Line>(myVariant);
		cout << "The assignment is done:" << myLine << endl;
	}
	catch (boost::bad_get& error)
	{
		/*Throw a boost::bad_get exception when the variant didn¡¯t contain a line.*/
		cout << "Variant doesn't contain a Line. Exception: " << error.what() << endl;
	}

	/*Create a variant visitor that moves the shapes.*/
	Visitor myVisitor(1.0, 2.0);
	/*Use the boost::apply_visitor(visitor, variant) global function to move the shape. */
	boost::apply_visitor(myVisitor, myVariant);
	/*Print the shape afterwards to check if the visitor indeed changed the coordinates.*/
	cout << "After the movement:" << myVariant << endl;


	return 0;
}

ShapeType CreateShape() {
	std::cout << "Please choose one kind of shape by entering the following number (1 for Point, 2 for Line, and 3 for Circle): " << std::endl;
	int choice;
	std::cin >> choice;
	ShapeType result;
	switch (choice) {
	case 1:
		result = Point();
		break;
	case 2:
		result = Line();
		break;
	case 3:
		result = Circle();
		break;
	default:
		std::cout << "Invalid choice. Default to Point." << std::endl;
		result = Point();
		break;
	}
	return result;
}
