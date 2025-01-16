#include <iostream>
#include "Point.hpp"
#include <sstream>
#include <cmath>


namespace ZehaoYang {
	namespace CAD {
		// Colon Syntax, 构造函数可以通过冒号语法直接初始化类的成员变量。
		// 这种方式效率更高，因为它避免了先调用默认构造函数，再通过赋值运算符初始化的额外开销。
		// 不使用冒号语法：先调用默认构造函数初始化 x 和 y，然后再通过赋值运算符设置值。
		Point::Point():Shape(), m_x(0.0), m_y(0.0) {
			std::cout << "Point default constructor is called" << std::endl;
			//Initialize m_x and m_y as 0.0 and 0.0

		}

		Point::Point(double x_0, double y_0): Shape(), m_x(x_0), m_y(y_0) {
			std::cout << "Point constructor with and x- and y-coordinates is called." << std::endl;
		}

		Point::Point(const Point& other): Shape(other),m_x(other.m_x), m_y(other.m_y) {
			std::cout << "Point copy constructor is called" << std::endl;
		}

		Point::~Point() {
			std::cout << "Point destructor is called" << std::endl;

		}

		//double Point::X() const {
		//	return m_x;
		//}
		//
		//double Point::Y() const {
		//	return m_y;
		//}
		//
		//void Point::X(double newx) {
		//	m_x = newx;
		//}
		//
		//void Point::Y(double newy) {
		//	m_y = newy;
		//}

		std::string Point::ToString() const {
			std::stringstream ss;
			std::string s = Shape::ToString();
			ss << s <<" Point (" << m_x << ", " << m_y << ")";
			return ss.str();
		}

		double Point::Distance() const {
			return std::sqrt(m_x * m_x + m_y * m_y);
		}

		double Point::Distance(const Point& p) const {
			double p1 = m_x - p.m_x;
			double p2 = m_y - p.m_y;
			return std::sqrt(p1 * p1 + p2 * p2);

		}

		Point Point::operator - () const {
			return Point(-m_x, -m_y);
		}

		Point Point::operator * (double factor) const {
			return Point(m_x * factor, m_y * factor);
		}

		Point Point::operator + (const Point& p) const {
			return Point(m_x + p.m_x, m_y + p.m_y);
		}

		bool Point::operator == (const Point& p) const {
			return (m_x == p.m_x) && (m_y == p.m_y);
		}

		Point& Point::operator = (const Point& source) {
			if (this == &source) {
				return *this;
			}
			Shape::operator=(source);
			// 调用基类的赋值运算符，处理基类的成员变量赋值。
			this->m_x = source.m_x;
			this->m_y = source.m_y;
			return *this;
		}

		Point& Point::operator *= (double factor) {
			this->m_x *= factor;
			this->m_y *= factor;
			return *this;
		}

		Point::Point(double value)
		{
			m_x = value;
			m_y = value;
		}

		std::ostream& operator << (std::ostream& os, const Point& p)
		{
			os << "Point (" << p.m_x << ", " << p.m_y << ")";
			return os;
		}

		void Point::Draw() const {
			std::cout << "Point is drawn." << std::endl;
		}
	}
}