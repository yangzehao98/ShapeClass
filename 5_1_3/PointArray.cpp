#include "PointArray.hpp"

namespace ZehaoYang
{
	namespace Containers {

		PointArray::PointArray() :Array<Point>()            //default constructor
		{
		}
		PointArray::PointArray(int size) : Array<Point>(size)
		{
		}
		PointArray::PointArray(const PointArray& other) : Array<Point>(other)
		{
		}
		PointArray::~PointArray()
		{
		}
		PointArray& PointArray::operator=(const PointArray& source)
		{
			if (this == &source)
			{
				return *this;
			}
			Array<Point>::operator=(source);
			return *this;
		}

		double PointArray::Length() const
		{
			double totalLength = 0.0;
			if (PointArray::Size() == 1)
			{
				return totalLength;
			}
			else
			{
				for (int i = 0; i < PointArray::Size() - 1; i++)
				{
					totalLength += PointArray::GetElement(i).Distance(PointArray::GetElement(i + 1));
				}
				return totalLength;
			}
		}
	}
}
