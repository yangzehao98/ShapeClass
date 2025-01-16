//Visitor.hpp
// 
// The header file for the Visitor.cpp.
//
// @Author Zehao Yang
// @Version June 7, 2023


#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include "Stack.hpp"
#include "StackException.hpp"
#include "ArrayException.hpp"
#include <iostream>
#include "boost/variant.hpp"

using namespace ZehaoYang::CAD;// Use the full namespace for Point class

namespace ZehaoYang 
{
	namespace Containers
	{
		/*A visitor is a class derived from boost::static_visitor<T>
		that has for each type that can be stored an operator () with the type as argument. */
		class Visitor : public boost::static_visitor<void>
		{
		private:
			double m_dx;
			double m_dy;
		public:
			Visitor(double vx, double vy);
			void operator () (Point& p) const;
			void operator () (Line& l) const;
			void operator () (Circle& c) const;
		};
	}
}