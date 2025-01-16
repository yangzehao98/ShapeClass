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

			const Point& CenterPoint() const;//ʹ��const��ֹ���ص�centrepoint���޸ģ����ص���centrepoint�����ã���ֹcentrepoint����������ʡ�ڴ�
			void Radius(double r);
			void CenterPoint(const Point& center);
			double Radius() const;
			double Diameter() const;
			double Area() const;
			double Circumference() const;
			std::string ToString() const override;
			Circle& operator = (const Circle& source);
			friend std::ostream& operator << (std::ostream& os, const Circle& cc);
			virtual void Draw() const override; //virtual �ؼ������������ѡ
		};

		//std::ostream& operator << (std::ostream& os, const Circle& cc);
	}
}
#endif