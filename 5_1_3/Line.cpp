#include "Line.hpp"
#include "Point.hpp"

namespace ZehaoYang {
	namespace CAD {

		Line::Line():Shape(), startPoint(Point()), endPoint(Point()) {
			std::cout << "Line default constructor is called" << std::endl;
		}

		Line::Line(const Point& p1, const Point& p2): Shape(), startPoint(p1), endPoint(p2){
			std::cout << "Line constructor with start- and end-point is called" << std::endl;
		}

		Line::Line(const Line& another): Shape(another), startPoint(another.startPoint), endPoint(another.endPoint) {
			std::cout << "Line copy constructor is called" << std::endl;
		}

		Line::~Line() {
			std::cout << "Line destructor is called" << std::endl;
		}

		Point Line::p1() const {
			return startPoint;
		}

		Point Line::p2() const {
			return endPoint;
		}

		void Line::p1(const Point& p1) {
			startPoint = p1;
		}

		void Line::p2(const Point& p2) {
			endPoint = p2;
		}

		std::string Line::ToString() const {
			std::string s = Shape::ToString();
			return s + " Line("  + startPoint.ToString() + ", " + endPoint.ToString() + ")";
		}

		double Line::Length() const {
			return startPoint.Distance(endPoint);
		}

		Line& Line::operator = (const Line& source) {
			if (this == &source) {
				return *this;
			}
			Shape::operator=(source);
			this->startPoint = source.startPoint;
			this->endPoint = source.endPoint;
			return *this;
		}

		std::ostream& operator << (std::ostream& os, const Line& l)
		{
			os << "Line (" << l.startPoint << ", " << l.endPoint << ")";
			return os;
		}
		void Line::Draw() const {
			std::cout << "Line is drawn" << std::endl;
		}
	}
}
