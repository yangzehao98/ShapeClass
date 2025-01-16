#ifndef POINTARRAY_HPP
#define POINTARRAY_HPP

#include "Array.hpp"
#include "Point.hpp"
using namespace ZehaoYang::CAD;
// concrete inheritance
namespace ZehaoYang {
	namespace Containers
	{
		class PointArray : public Array<Point>
		{
		public:
			PointArray();
			PointArray(int size);
			PointArray(const PointArray& source);
			virtual ~PointArray();
			PointArray& operator=(const PointArray& source); //Add assignment operator
			double Length() const;//Add specific functionality
		};
	}
}

#endif