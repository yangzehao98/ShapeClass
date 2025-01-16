// StackEmptyException.hpp
//
// @Author Zehao Yang
// @Version June 3, 2023

#ifndef StackEmptyException_hpp
#define StackEmptyException_hpp

#include "StackException.hpp"
#include <sstream>

namespace ZehaoYang {
    namespace Containers {
        class StackEmptyException : public StackException
        {
        public:
            virtual std::string GetMessage() const
            {
                std::stringstream ss;
                ss << "Error: Stack Is Empty.";
                return ss.str();
            }
        };
    }
}
#endif 
