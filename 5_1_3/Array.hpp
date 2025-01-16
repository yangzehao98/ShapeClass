#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Point.hpp"
#include "OutOfBoundsException.hpp"
#include "ArrayException.hpp"
namespace ZehaoYang {
	namespace Containers {

		template <typename T>
		class Array {
		private:
			int m_size;
			T* m_data;
			static int m_defaultSize;
			/*在类的所有实例之间共享
			只有一个副本存在于内存中
			属于类而不是对象实例*/

			// static不能使用 this 指针，const可以，const承诺不修改对象的状态
			//
		public:
			Array();
			Array(int size);
			Array(const Array& arr);
			~Array();
			Array& operator = (const Array<T>& source);

			int Size() const;
			void SetElement(int index, const T& p);
			const T& GetElement(int index) const;
			T& operator [] (int index);
			const T& operator [] (int index) const;
			// 第一个const是为了防止函数修改返回的const，第二个const是为了防止修改对象的成员变量
			static int DefaultSize(); //Add static functions to get the default size.
			static void DefaultSize(int size); //Add static functions to set the default size.
			// static只需要加一次在hpp中
		};
	}
}
#ifndef Array_cpp // Must be the same name as in source file #define
#include "Array.cpp"
#endif
#endif