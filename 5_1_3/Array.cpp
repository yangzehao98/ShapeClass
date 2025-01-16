#ifndef Array_cpp
#define Array_cpp


#include "Array.hpp"
#include <iostream>

// template<typename T> class Array { ... };
//template<class T> class Array { ... };
// ������ͬ������ģ��������������� T ��һ��ģ��������������������͡����ڶ���template<typename T>��


namespace ZehaoYang {
	namespace Containers {
		//Ҫ���� namespace �ڲ�
		//Ҫ�����к�������֮ǰ
		//ֻ��ʼ��һ��
		template<typename T>
		int Array<T>::m_defaultSize = 10;

		template<typename T>
		Array<T>::Array() : m_size(m_defaultSize), m_data(new T[m_defaultSize]) {
		}
		// // ���캯���������������ȫһ�������Բ���Ҫ�ظ�д<T>
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
			// &arr ��һ�����ã���ʾ������ Array �ĸ���������ֱ��ָ�򴫵ݸ������� Array ����
			if (this == &arr) {
				// &source �Ǹ�ֵ�����ұ߶���ĵ�ַ
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
			if (index < 0 || index >= m_size) {  // ���������Χ
				throw OutOfBoundsException(index);  // �׳��쳣
			}
			m_data[index] = p;
		}

		template<typename T>
		const T& Array<T>::GetElement(int index) const {
			if (index < 0 || index >= m_size) {  // ���������Χ
				throw OutOfBoundsException(index);  // �׳��쳣
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
		// ��const�汾��operator[]�����ؿ��޸ĵ����ã�֧�ֶ�д������

		template <typename T>
		const T& Array<T>::operator [] (int index) const {
			if (index < 0 || index >= m_size)
			{
				throw OutOfBoundsException(index);
			}
			return m_data[index];
		}
		// const�汾��operator[]������const���ã�ֻ֧�ֶ���������֧��д������
		// ���const��֤����ֵ�����޸ģ�������������ò����޸ģ��ұ�const����дȨ�ޣ���ֹ�޸��ڲ�����ֵ

		// int x = 10;       // ����һ�����ͱ��� x
		// int* p = &x;      // ʹ�� & ��ȡ x �ĵ�ַ
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