#ifndef ERROR_CHECK_H
#define ERROR_CHECK_H

#include <iostream>
#include <exception>

using namespace std;

class ERROR_CHECK : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "ERROR === Function return";
    }
};

#endif // ERROR_CHECK_H
