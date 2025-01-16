#ifndef ARRAYEXCEPTION_HPP
#define ARRAYEXCEPTION_HPP
#include <iostream>

namespace ZehaoYang
{
	namespace Containers {
		class ArrayException
		{
		public:
			virtual std::string GetMessage() const = 0;
		};
	}
}

#endif