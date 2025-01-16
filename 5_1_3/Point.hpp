#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Shape.hpp"
// For example the << operator for sending the point or line to the std::ostream class had to be a global function and thus can’t access the private members.Move the << operator of Point and Line 
// inside the class definition and declare it as friend.The function remains a global function but it can now access the data members directly without the need for calling the getters or ToString() function.

namespace ZehaoYang {
	namespace CAD {
		// 公共继承（public Shape）, 受保护继承（protected Shape）, 私有继承（private Shape）
		class Point:public Shape {
		private:
			double m_x;
			double m_y;

		public:
			Point();
			Point(double x_0, double y_0);
			Point(const Point& other);
			// 值传递 (Call by Value)：
			// function (type p) 在函数中使用值传递时，会创建传入对象的副本，这就需要调用拷贝构造函数。这种方式不会修改原始对象。
			// 引用传递 (Call by Reference)：
			// function (type& P) 在函数中使用引用传递时，不会创建传入对象的副本，而是直接使用原始对象。这种方式会修改原始对象。修改被传递过来的p的内容
			~Point();
			inline double X() const;
			// const保证了函数不会修改成员变量的值，比如point1和point2，这个设置保证
			// 如果我们修改了point1的x, y值，point2的值不会被修改
			inline double Y() const;
			// 这个叫做normal inline function
			void X(double x) { this->m_x = x; }
			// 如果写作void SetX(const double x)，这个是保证在函数内部不会修改x的值,比如函数内部有 x = x+1,这个就无效化了。
			//
			void Y(double y) { this->m_y = y; }
			// 这个叫做default inline function，就是在类内部定义的函数，自动就是inline的
			std::string ToString() const override;
			// 如果写作const std::string ToString(); 这个是保证返回值不被修改，比如p.ToString() += " modified";  
			double Distance() const;
			double Distance(const Point& p) const;

			Point operator -() const;
			Point operator *(double factor) const;
			Point operator + (const Point& p) const;
			bool operator == (const Point& p) const;
			Point& operator = (const Point& source);
			Point& operator *= (double factor);

			explicit Point(double value);
			// 显式转换，防止隐式转换，比如Point p = 1.0; 这个就会报错（隐式转换不会报错）
			friend std::ostream& operator << (std::ostream& os, const Point& p);
			virtual void Draw() const override; //virtual 关键词在这里可以选

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
		//inline函数需要在头文件中定义完整的实现，以便编译器能够在调用时直接展开函数体。
		//inline函数的定义必须在调用之前，否则编译器无法展开函数体。
		// std::ostream& operator << (std::ostream& os, const Point& p);
		// ostream写为global function，因为ostream是全局的，不是Point的一部分
	}
}
#endif

//virtual和override都在hpp写，不在cpp写