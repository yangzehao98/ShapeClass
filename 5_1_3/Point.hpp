#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Shape.hpp"
// For example the << operator for sending the point or line to the std::ostream class had to be a global function and thus can��t access the private members.Move the << operator of Point and Line 
// inside the class definition and declare it as friend.The function remains a global function but it can now access the data members directly without the need for calling the getters or ToString() function.

namespace ZehaoYang {
	namespace CAD {
		// �����̳У�public Shape��, �ܱ����̳У�protected Shape��, ˽�м̳У�private Shape��
		class Point:public Shape {
		private:
			double m_x;
			double m_y;

		public:
			Point();
			Point(double x_0, double y_0);
			Point(const Point& other);
			// ֵ���� (Call by Value)��
			// function (type p) �ں�����ʹ��ֵ����ʱ���ᴴ���������ĸ����������Ҫ���ÿ������캯�������ַ�ʽ�����޸�ԭʼ����
			// ���ô��� (Call by Reference)��
			// function (type& P) �ں�����ʹ�����ô���ʱ�����ᴴ���������ĸ���������ֱ��ʹ��ԭʼ�������ַ�ʽ���޸�ԭʼ�����޸ı����ݹ�����p������
			~Point();
			inline double X() const;
			// const��֤�˺��������޸ĳ�Ա������ֵ������point1��point2��������ñ�֤
			// ��������޸���point1��x, yֵ��point2��ֵ���ᱻ�޸�
			inline double Y() const;
			// �������normal inline function
			void X(double x) { this->m_x = x; }
			// ���д��void SetX(const double x)������Ǳ�֤�ں����ڲ������޸�x��ֵ,���纯���ڲ��� x = x+1,�������Ч���ˡ�
			//
			void Y(double y) { this->m_y = y; }
			// �������default inline function�����������ڲ�����ĺ������Զ�����inline��
			std::string ToString() const override;
			// ���д��const std::string ToString(); ����Ǳ�֤����ֵ�����޸ģ�����p.ToString() += " modified";  
			double Distance() const;
			double Distance(const Point& p) const;

			Point operator -() const;
			Point operator *(double factor) const;
			Point operator + (const Point& p) const;
			bool operator == (const Point& p) const;
			Point& operator = (const Point& source);
			Point& operator *= (double factor);

			explicit Point(double value);
			// ��ʽת������ֹ��ʽת��������Point p = 1.0; ����ͻᱨ����ʽת�����ᱨ��
			friend std::ostream& operator << (std::ostream& os, const Point& p);
			virtual void Draw() const override; //virtual �ؼ������������ѡ

		};
		/*Use normal inline (outside the class declaration) for the getters*/
		inline double Point::X() const
		{
			return m_x;
		}
		inline double Point::Y() const
		{
			return m_y;
		}
		//inline������Ҫ��ͷ�ļ��ж���������ʵ�֣��Ա�������ܹ��ڵ���ʱֱ��չ�������塣
		//inline�����Ķ�������ڵ���֮ǰ������������޷�չ�������塣
		// std::ostream& operator << (std::ostream& os, const Point& p);
		// ostreamдΪglobal function����Ϊostream��ȫ�ֵģ�����Point��һ����
	}
}
#endif

//virtual��override����hppд������cppд