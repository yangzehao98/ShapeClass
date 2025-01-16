#ifndef Array_cpp
#define Array_cpp


#include "Array.hpp"
#include <iostream>

// template<typename T> class Array { ... };
//template<class T> class Array { ... };
// 二者相同，都是模板类的声明，其中 T 是一个模板参数，可以是任意类型。现在多用template<typename T>。


namespace ZehaoYang {
	namespace Containers {
		//要放在 namespace 内部
		//要在所有函数定义之前
		//只初始化一次
		template<typename T>
		int Array<T>::m_defaultSize = 10;

		template<typename T>
		Array<T>::Array() : m_size(m_defaultSize), m_data(new T[m_defaultSize]) {
		}
		// // 构造函数名必须和类名完全一样，所以不需要重复写<T>
		template<typename T>
		Array<T>::Array(int size) : m_size(size), m_data(new T[size]) {
		}

		template<typename T>
		Array<T>::Array(const Array& arr) {
			this->m_data = new T[arr.m_size];
			this->m_size = arr.m_size;
			for (int i = 0; i < this->m_size; i++) {
				this->m_data[i] = arr.m_data[i];
			}
		}
		template<typename T>
		Array<T>::~Array() {
			delete[] m_data;
		}
		template<typename T>
		Array<T>& Array<T>::operator = (const Array<T>& arr) {
			// &arr 是一个引用，表示它不是 Array 的副本，而是直接指向传递给函数的 Array 对象
			if (this == &arr) {
				// &source 是赋值操作右边对象的地址
				return *this;
			}
			delete[] m_data;
			this->m_size = arr.m_size;
			this->m_data = new CAD::Point[arr.m_size];
			for (int i = 0; i < this->m_size; i++) {
				this->m_data[i] = arr.m_data[i];
			}
			return *this;
		}
		template<typename T>
		int Array<T>::Size() const {
			return m_size;
		}

		template<typename T>
		void Array<T>::SetElement(int index, const T& p) {
			if (index < 0 || index >= m_size) {  // 检查索引范围
				throw OutOfBoundsException(index);  // 抛出异常
			}
			m_data[index] = p;
		}

		template<typename T>
		const T& Array<T>::GetElement(int index) const {
			if (index < 0 || index >= m_size) {  // 检查索引范围
				throw OutOfBoundsException(index);  // 抛出异常
			}
			return m_data[index];
		}
		template <typename T>
		T& Array<T>::operator [] (int index) {
			if (index < 0 || index >= m_size)
			{
				throw OutOfBoundsException(index);
			}
			return m_data[index];
		}
		// 非const版本的operator[]：返回可修改的引用，支持读写操作。

		template <typename T>
		const T& Array<T>::operator [] (int index) const {
			if (index < 0 || index >= m_size)
			{
				throw OutOfBoundsException(index);
			}
			return m_data[index];
		}
		// const版本的operator[]：返回const引用，只支持读操作，不支持写操作。
		// 左边const保证返回值不被修改，比如这里的引用不被修改，右边const不给写权限，防止修改内部变量值

		// int x = 10;       // 定义一个整型变量 x
		// int* p = &x;      // 使用 & 获取 x 的地址
		template<typename T>
		int Array<T>::DefaultSize() {
			return m_defaultSize;
		}

		template<typename T>
		void Array<T>::DefaultSize(int size){
			m_defaultSize = size;
		}
	}
}

#endif