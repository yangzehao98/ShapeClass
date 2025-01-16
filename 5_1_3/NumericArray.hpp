#ifndef NUMERICARRAY_HPP
#define NUMERICARRAY_HPP
#include "Array.hpp"
#include "ArraySizeException.hpp"

//generic inheritance

namespace ZehaoYang {
	namespace Containers {
		template <typename T>
		class NumericArray : public Array<T> {
		public:
			NumericArray();
			NumericArray(int size);
			NumericArray(const NumericArray<T>& source);
			virtual ~NumericArray();
			NumericArray<T>& operator=(const NumericArray <T> &source);
			NumericArray<T> operator*(double factor) const;
			NumericArray<T> operator+(const NumericArray<T>& arr) const;
			double DotProduct(const NumericArray<T>& arr) const;
		};
	}
}

#ifndef NUMERICARRAY_CPP
#include "NumericArray.cpp"
#endif
#endif
