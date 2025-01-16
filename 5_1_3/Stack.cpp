#ifndef Stack_cpp
#define Stack_cpp

#include "Array.hpp"
#include"OutOfBoundsException.hpp"
#include"Stack.hpp"

namespace ZehaoYang{
	namespace Containers {
		
		template <typename T, int size>
		Stack<T, size>::Stack() : m_current(Array<T>(size)), s_size(0)
		{
		}
		/*template <typename T, int size>
		Stack<T, size>::Stack(int size) : m_current(Array<T>(size)), s_size(size)
		{
		}*/
		template <typename T, int size>
		Stack<T, size>::Stack(const Stack<T, size>& other) : m_current(other.m_current), s_size(other.s_size)
		{
		}
		template <typename T, int size>
		Stack<T, size>::~Stack()
		{
		}
		template <typename T, int size>
		Array<T> Stack<T, size>::Current() const
		{
			return m_current;
		}
		template <typename T, int size>
		int Stack<T, size>::Size() const
		{
			return s_size;
		}
		template <typename T, int size>
		void Stack<T, size>::Push(const T& element)
		{
			try {
				if (s_size >= m_current.Size()) {
					throw StackFullException();
				}
				m_current[s_size] = element;
				++s_size;
			}
			catch (const OutOfBoundsException&) {
				throw StackFullException();
			}
		}
		template <typename T, int size>
		T Stack<T, size>::Pop()
		{
			try {
				if (s_size <= 0) {
					throw StackEmptyException();
				}
				T value = m_current[s_size - 1];
				--s_size;
				return value;
			}
			catch (const OutOfBoundsException&) {
				s_size = 0;  // Reset size to 0
				throw StackEmptyException();
			}
			// 下次 Pop() 不会访问到这个"已删除"的元素
			// 下次 Push() 会覆盖这个位置
		}
		template <typename T, int size>
		Stack<T, size>& Stack<T, size>:: operator=(const Stack<T, size>& source) {
			if (this == &source) {
				return *this;
			}
			m_current = source.m_current;
			s_size = source.s_size;
			return *this;
		}
	}	
}

#endif