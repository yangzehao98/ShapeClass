//
#include "Circle.hpp"
#include <sstream>
#include <cmath>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

namespace ZehaoYang {
	namespace CAD {

		Circle::Circle(): Shape(), centerpoint(Point()), m_radius(0.0) {
			std::cout << "Circle default constructor is called" << std::endl;
		}
		Circle::Circle(const Point& center, double radius): Shape(), centerpoint(center), m_radius(radius) {
			std::cout << "Circle constructor with center and radius is called" << std::endl;
		}
		Circle::Circle(const Circle& other):Shape(other), centerpoint(other.centerpoint), m_radius(other.m_radius) {
			std::cout << "Circle copy constructor is called" << std::endl;
		}
		Circle::~Circle() {
			std::cout << "Circle destructor is called" << std::endl;
		}

		void Circle::Radius(double r) {
			m_radius = r;
		}
		void Circle::CenterPoint(const Point& center) {
			centerpoint = center;
		}
		const Point& Circle::CenterPoint() const {
			return centerpoint;
		}
		double Circle::Radius() const {
			return m_radius;
		}

		double Circle::Diameter() const {
			return 2 * m_radius;
		}

		double Circle::Circumference() const {
			return 2 * M_PI * m_radius;
		}

		double Circle::Area() const {
			return M_PI * m_radius * m_radius;
		}

		std::string Circle::ToString() const {
			std::stringstream ss;
			std::string s = Shape::ToString();
			ss << s << " Circle(" << centerpoint.ToString() << ", Radius: " << m_radius << ")";
			return ss.str();
		}

		Circle& Circle::operator = (const Circle& source) {
			if (this == &source) {
				return *this;
			}
			Shape::operator = (source);
			centerpoint = source.centerpoint;
			m_radius = source.m_radius;
			return *this;
		}

		std::ostream& operator << (std::ostream& os, const Circle& cc) {
			os << "Circle(" << cc.centerpoint << ", Radius: " << cc.m_radius << ")";
			return os;
		}

		void Circle::Draw() const {
			std::cout << "Circle is drawn" << std::endl;
		}
	}
}