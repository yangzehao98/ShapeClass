#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <stdlib.h>
#include <iostream>
#include <sstream>
namespace ZehaoYang {
	namespace CAD {

		class Shape
		{
		private:
			int m_id;
		public:
			Shape();
			Shape(const Shape& other);
			Shape& operator=(const Shape& source);
			virtual ~Shape();
			// 有了virtual关键字，调用析构函数的时候，不仅会调用Shape的析构函数，还会调用派生类的析构函数。否则只会调用Shape的析构函数。

			virtual std::string ToString() const;
			int ID() const;
			virtual void Draw() const = 0;
			// 纯虚函数，这个类是一个抽象类，不能实例化对象，只能作为基类/接口类，不需要在cpp文件中实现。
			virtual void Print() const;
		};
	}
}
#endif
