#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include <iostream>

namespace ZehaoYang {
	namespace Containers {
		template<typename T>
		NumericArray<T>::NumericArray() : Array<T>() {
		}

		template<typename T>
		NumericArray<T>::NumericArray(int size) : Array<T>(size) {
		}
		template<typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array<T>(source) {
		}

		template<typename T>
		NumericArray<T>::~NumericArray() {
		}

		template<typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray <T>& source)
		{
			if (this == &source)
			{
				return *this;
			}
			Array<T>::operator=(source);//Call the operator= in base template
			return *this;
		}

		template<typename T>
		NumericArray<T> NumericArray<T>::operator*(double factor) const {
			NumericArray<T> numeric_arr(Array<T>::Size());
			for (int i = 0; i < Array<T>::Size(); i++) {
				numeric_arr[i] = Array<T>::GetElement(i) * factor;
			}
			return numeric_arr;
		}

		template<typename T>
		NumericArray<T> NumericArray<T>:: operator+(const NumericArray<T>& arr) const
		{
			if (Array<T>::Size() != arr.Size())
			{
				throw ArraySizeException();
			}
			NumericArray<T> new_arr(Array<T>::Size());
			for (int i = 0; i < Array<T>::Size(); i++)
			{
				new_arr[i] = Array<T>::GetElement(i) + arr[i];
			}
			return new_arr;
		}

		template<typename T>
		double NumericArray<T>::DotProduct(const NumericArray<T>& arr) const {
			if (Array<T>::Size() != arr.Size()) {
				throw ArraySizeException();
			}
			double sum = 0;
			for (int i = 0; i < Array<T>::Size(); i++) {
				sum += Array<T>::GetElement(i) * arr[i];
			}
			return sum;
		}




	}
}

#endif