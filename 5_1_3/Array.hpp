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
			/*���������ʵ��֮�乲��
			ֻ��һ�������������ڴ���
			����������Ƕ���ʵ��*/

			// static����ʹ�� this ָ�룬const���ԣ�const��ŵ���޸Ķ����״̬
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
			// ��һ��const��Ϊ�˷�ֹ�����޸ķ��ص�const���ڶ���const��Ϊ�˷�ֹ�޸Ķ���ĳ�Ա����
			static int DefaultSize(); //Add static functions to get the default size.
			static void DefaultSize(int size); //Add static functions to set the default size.
			// staticֻ��Ҫ��һ����hpp��
		};
	}
}
#ifndef Array_cpp // Must be the same name as in source file #define
#include "Array.cpp"
#endif
#endif