#ifndef _Lib_Exception_H_
#define _Lib_Exception_H_

#include <stdexcept>

class list_is_empty: public std::underflow_error
{
public:
    list_is_empty():std::underflow_error("list is empty !!!")
    {

    }

};

class data_not_found: public std::runtime_error
{
    public:
    data_not_found(): std::runtime_error("data not found")
    {

    }
};

#endif /* _Lib_Exception_H_ */