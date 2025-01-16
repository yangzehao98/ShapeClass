#include <iostream>
#include "Point.hpp"
#include <sstream>
#include <cmath>


namespace ZehaoYang {
	namespace CAD {
		// Colon Syntax, ���캯������ͨ��ð���﷨ֱ�ӳ�ʼ����ĳ�Ա������
		// ���ַ�ʽЧ�ʸ��ߣ���Ϊ���������ȵ���Ĭ�Ϲ��캯������ͨ����ֵ�������ʼ���Ķ��⿪����
		// ��ʹ��ð���﷨���ȵ���Ĭ�Ϲ��캯����ʼ�� x �� y��Ȼ����ͨ����ֵ���������ֵ��
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
			// ���û���ĸ�ֵ��������������ĳ�Ա������ֵ��
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