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
			// ����virtual�ؼ��֣���������������ʱ�򣬲��������Shape����������������������������������������ֻ�����Shape������������

			virtual std::string ToString() const;
			int ID() const;
			virtual void Draw() const = 0;
			// ���麯�����������һ�������࣬����ʵ��������ֻ����Ϊ����/�ӿ��࣬����Ҫ��cpp�ļ���ʵ�֡�
			virtual void Print() const;
		};
	}
}
#endif
