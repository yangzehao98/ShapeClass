#ifndef STACK_HPP
#define STACK_HPP

#include "Array.hpp"
#include "StackException.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"
#include "OutOfBoundsException.hpp"

namespace ZehaoYang {
	namespace Containers {
		template <typename T, int size>
		class Stack {
		private:
			Array<T> m_current;
			int s_size;
		public:
			Stack();
			//Stack(int size);
			Stack(const Stack<T, size>& other);
			virtual ~Stack();
			Array<T> Current() const;
			void Push(const T& element);
			int Size() const;
			T Pop();
			Stack<T, size>& operator=(const Stack<T, size>& source);

		};

	}
}

#ifndef STACK_CPP
#include "Stack.cpp"
#endif
#endif /* Stack_hpp */