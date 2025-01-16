// StackException.hpp
// The base class for StackFullException and StackEmptyException. 
//
// @Author Zehao Yang
// @Version June 3, 2023

#ifndef StackException_hpp
#define StackException_hpp

namespace ZehaoYang {
    namespace Containers {
        class StackException
        {
        public:
            virtual std::string GetMessage() const = 0;
        };
    }
}
#endif /* StackException_hpp */
