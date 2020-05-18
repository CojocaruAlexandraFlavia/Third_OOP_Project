#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <exception>

class MyException : public std::exception
{
public:
    MyException () noexcept {}
    MyException (const MyException&) noexcept = default;
    MyException& operator= (const MyException&) noexcept = default;
    virtual ~MyException() noexcept = default;
    virtual const char* what() const noexcept
    {
        return "Persoana exista deja!";
    }
};

#endif // MYEXCEPTION_H
