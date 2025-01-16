#include "Shape.hpp"

namespace ZehaoYang {
	namespace CAD {

		Shape::Shape() : m_id(rand())
		{
			std::cout << "Shape default constructor is called" << std::endl;
		}

		Shape::Shape(const Shape& other) : m_id(other.m_id)
		{
			std::cout << "Shape copy constructor is called" << std::endl;
		}
		Shape::~Shape()
		{
			std::cout << "Shape destructor is called" << std::endl;
		}

		Shape&Shape::operator=(const Shape& source)
		{
			if (this == &source)
			{
				return *this;
			}
			else
			{
				m_id = source.m_id;
				return *this;
			}
		}

		std::string Shape::ToString() const
		{
			std::stringstream ss;
			ss << "Shape ID: " << m_id;
			return ss.str();
		}

		int Shape::ID() const
		{
			return m_id;
		}

		void Shape::Print() const
		{
			std::cout << ToString() << std::endl;
		}
	}
}