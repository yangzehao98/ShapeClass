#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Point.hpp"
#include "Shape.hpp"

namespace ZehaoYang {
	namespace CAD {
		class Circle: public Shape {
		private:
			Point centerpoint;
			double m_radius;
		public:
			Circle();
			Circle(const Point& center, double r);
			Circle(const Circle& c);
			~Circle();

			const Point& CenterPoint() const;//使用const防止返回的centrepoint被修改；返回的是centrepoint的引用，防止centrepoint被拷贝，节省内存
			void Radius(double r);
			void CenterPoint(const Point& center);
			double Radius() const;
			double Diameter() const;
			double Area() const;
			double Circumference() const;
			std::string ToString() const override;
			Circle& operator = (const Circle& source);
			friend std::ostream& operator << (std::ostream& os, const Circle& cc);
			virtual void Draw() const override; //virtual 关键词在这里可以选
		};

		//std::ostream& operator << (std::ostream& os, const Circle& cc);
	}
}
#endif