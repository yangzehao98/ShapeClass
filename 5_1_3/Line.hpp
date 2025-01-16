#ifndef LINE_HPP
#define LINE_HPP

#include "Point.hpp"
#include "Shape.hpp"

namespace ZehaoYang {
	namespace CAD {
		class Line: public Shape {
		private:
			Point startPoint;
			Point endPoint;
		public:
			Line();
			Line(const Point& p1, const Point& p2);
			Line(const Line& another);
			~Line();
			Point p1() const;
			Point p2() const;
			void p1(const Point& p1);
			void p2(const Point& p2);
			std::string ToString() const override;
			double Length() const;
			Line& operator = (const Line& source);
			friend std::ostream& operator << (std::ostream& os, const Line& l);
			virtual void Draw() const override; //virtual 关键词在这里可以选
		};

		//std::ostream& operator << (std::ostream& os, const Line& l);
	}
}
#endif
