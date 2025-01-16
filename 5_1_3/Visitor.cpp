// Visitor.hpp
// 
// The source file for the Visitor.cpp.
//
// @Author Zehao Yang
// @Version June 7, 2023

#include "Visitor.hpp"

namespace ZehaoYang {
	namespace Containers {
		Visitor::Visitor(double vx, double vy): m_dx(vx), m_dy(vy)
		{
		}
		/*The template argument is the return type of the operators ().*/
		void Visitor::operator () (Point& p) const
		{
			p.X(p.X() + m_dx);
			p.Y(p.Y() + m_dy);
		}

		void Visitor::operator() (Line& l) const
		{
			Point startp = l.p1();
			startp.X(l.p1().X() + m_dx);
			startp.Y(l.p1().Y() + m_dy);
			l.p1(startp);
			Point endp = l.p2();
			endp.X(l.p2().X() + m_dx);
			endp.Y(l.p2().Y() + m_dy);
			l.p2(endp);
		}

		void Visitor::operator() (Circle& c) const
		{
			Point cp = c.CenterPoint();
			cp.X(c.CenterPoint().X() + m_dx);
			cp.Y(c.CenterPoint().Y() + m_dy);
			c.CenterPoint(cp);
		}
	}
}