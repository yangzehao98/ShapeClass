// StackFullException.hpp
//
// @Author Zehao Yang
// @Version June 3, 2023

#ifndef StackFullException_hpp
#define StackFullException_hpp

#include "StackException.hpp"
#include <sstream>

namespace ZehaoYang {
    namespace Containers {
        class StackFullException : public StackException
        {
        public:
            virtual std::string GetMessage() const
            {
                std::stringstream ss;
                ss << "Error: Stack Is Full.";
                return ss.str();
            }
        };
    }
}
#endif 
