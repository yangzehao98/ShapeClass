#ifndef OUTOFBOUNDSEXCEPTION_HPP
#define OUTOFBOUNDSEXCEPTION_HPP
#include <sstream>

#include "ArrayException.hpp"
namespace ZehaoYang
{
	namespace Containers {
		class OutOfBoundsException : public ArrayException
		{
		private:
			int m_index;
		public:
			OutOfBoundsException(int index)
			{
				m_index = index;
			}//Avoiding implicit conversions.
			std::string GetMessage() const
			{
				std::stringstream ss;
				ss << "Error: Index " << m_index << " is out of bounds.";
				return ss.str();
			}
		};
	}
}
#endif