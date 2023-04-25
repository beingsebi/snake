#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
#include <string>
using std::runtime_error;
using std::string;

class apk_error : public runtime_error
{
    using runtime_error::runtime_error;
};

class file_error : public apk_error
{
public:
    explicit file_error(const string s) : apk_error{"File error: " + s + "\n"} {}
};

class score_error : public apk_error
{
public:
    explicit score_error(const string s) : apk_error{"Score error: " + s + "\n"} {}
};
#endif