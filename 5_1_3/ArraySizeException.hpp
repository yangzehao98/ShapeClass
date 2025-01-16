#ifndef ARRAYSIZEEXCEPTION_HPP
#define ARRAYSIZEEXCEPTION_HPP
#include "ArrayException.hpp"
namespace ZehaoYang
{
	namespace Containers {
		class ArraySizeException : public ArrayException
		{
		public:
			ArraySizeException() : ArrayException() {}
			virtual std::string GetMessage() const override
			{
				return "The array sizes don't match";
			}
		};

	}
}
#endif